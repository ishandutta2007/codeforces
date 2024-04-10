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
const int mxN = 1e5+1, oo = 1e9;
const long long MOD = 998244353;
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
int main() {
    int n; cin >> n;
    vi a(n);
    for(auto& i : a) cin >> i;
    ll cnt[100]={};
    for(int i=0;i<n;++i) {
        cnt[to_string(a[i]).length()]++;
    }
    mint res=0;
    for(int i=0;i<n;++i) {
        // front
        auto merge = [&](string s, string t) {
            string ans;
            while(!s.empty() or !t.empty()) {
                if(!s.empty()) {
                    ans.push_back(s.back());
                    s.pop_back();
                }
                if(!t.empty()) {
                    ans.push_back(t.back());
                    t.pop_back();
                }
            }
            mint rs=0;
            while(!ans.empty()) {
                rs = rs*10 +(ans.back()-'0');
                ans.pop_back();
            }
            return rs;
        };
        string t = to_string(a[i]);
        for(int o=1;o<=11;++o) {
            if(!cnt[o]) continue;
            string s(o,'0');
            res+=(mint)merge(t,s)*cnt[o];
            res+=(mint)merge(s,t)*cnt[o];
        }
    }
    cout << res.d << '\n';
}