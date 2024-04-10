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
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
vi zalgo(const string& s) {
    int n = s.size();
    vi z(n);
    for (int i=1,x=0,y=0;i<n;++i) {
        if(i<=y) z[i] = min(z[i-x], y-i+1);
		if(i+z[i]>y) {
            while(i+z[i]<n and s[i+z[i]]==s[z[i]]) {
                ++z[i];
            }
            x=i;
            y=z[i]+i-1;
		}
	}
    return z;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string aa,l,r;
    cin >> aa >> l >> r;
    int n = aa.size();
    auto lcps = zalgo(l+'#'+aa);
    lcps.erase(lcps.begin(),lcps.begin()+l.size()+1);
    auto lcpb = zalgo(r+'#'+aa);
    lcpb.erase(lcpb.begin(),lcpb.begin()+r.size()+1);
    
    auto goodL = [&](int i) {
        int lcp = lcps[i];
        if(lcp==l.size()) return true;
        return l[lcp]<=aa[i+lcp];
    };
    auto goodR = [&](int i) {
        int lcp = lcpb[i];
        if(lcp==r.size()) return true;
        return r[lcp]>=aa[i+lcp];
    };
    auto goods = [&](int i) {
        int a=i-r.size();
        int b = i-l.size();
        if(a>=0 and !goodR(a)) ++a;
        if(b>=0 and !goodL(b)) --b;
        a = max(a,0), b = max(b,-1);
        b++;
        b = max(b,a);
        return make_pair(a,b);

    };
    vector<mint> pref(n+2);
    pref[1]=1;
    mint dp;
    for(int i=1;i<=n;++i) {
        auto [a,b] = goods(i);
        
        dp=pref[b]-pref[a];
        if(aa[i-1]=='0') {
            pref[i]=pref[i-1];
        }
        pref[i+1]=dp + pref[i];

    }
    cout << dp << '\n';



}