#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 3.1e6+1, oo = 1e9;
const long long MOD = 1e9+7;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
const mint base = 1234567;
mint pw[mxN], pw2[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    string s0,t; cin >> s0 >> t;

    vector<mint> g[26];
    for(int j=0;j<26;++j) {
        auto& v = g[j];
        v.resize(n+1);
        for(int i=1;i<=n;++i) {
            v[i]=v[i-1]*2+(t[i-1]=='a'+j);
        }
    }

    pw[0]=1,pw2[0]=1;
    for(int i=1;i<mxN;++i) pw[i] = pw[i-1]*base, pw2[i] = pw2[i-1]*2;
    struct hstring {
        vector<mint> h;
        int size() {return h.size()-1;}
        hstring(){}
        hstring(const string& s) {
            h.resize(s.size()+1);
            for(int i=1;i<=size();++i) {
                h[i]=h[i-1]*base+s[i-1];
            }
        }
        mint get(int i, int sz) {
            if(sz==0) return 0;
            return h[i+sz]-h[i]*pw[sz];
        }
        int count(hstring& o) {
            int ans=0;
            for(int i=0;i+o.size()<=size();++i) {
                if(get(i,o.size()) == o.h.back()) ans++;
            }
            return ans;
        }
    };
    while(q--) {
        int k; cin >> k; string s; cin >> s;
        string sst = s0;
        int stid=0;
        while(stid<k and sst.size()<s.size()) {
            sst = sst+t[stid]+sst;
            ++stid;
        }
        hstring st(sst);
        int sz = s.size();
        if(st.size()<sz) {
            cout << "0\n";
        } else {
            hstring hs(s);
            int dif = k-stid;
            mint ans = pw2[dif]*st.count(hs);
            for(int i=0;i<sz;++i) {
                // borders
                int j = sz-i-1;
                mint f = st.get(0, i), b = st.get(st.size()-j,j);
                if(f == hs.get(j+1,i) and b == hs.get(0,j)) {
                    assert(0<=j and j<sz);
                    int id = s[j]-'a';
                    assert(0<=id and id<26);
                    ans += g[id][k]-pw2[dif]*g[id][stid];
                }
            }
            cout << ans.d << '\n';
        }
    }
}