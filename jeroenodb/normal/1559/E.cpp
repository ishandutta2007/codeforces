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
    mdint (long long _d) : d(_d%MOD){};
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
const int store=1e5 + 1;
bitset<store> sieve={};
int factor[mxN];
bitset<store>  parity= {}, bad ;
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j]=i;
                    sieve[j] = true;
                }
            }
        }
    }
    for(int i=2;i<store;++i) {
        bad[i] = bad[i/factor[i]] or (factor[i]==factor[i/factor[i]]);
        parity[i] = !parity[i/factor[i]];
    }
}
using  mint = mdint<MD>;
mint solve(vi l, vi r, int m) {
    int n = l.size();
    for(int i=0;i<n;++i) {
        if(r[i]<l[i]) return 0;
        r[i]-=l[i];
        m-=l[i];
    }
    if(m<0) return 0;
    vector<mint> dp(m+1);
    dp[0]=1;
    for(auto& i : r) {
        vector<mint> ndp(m+1);
        mint sm=0;
        for(int j=0;j<=m;++j) {
            sm+=dp[j];
            if(j-i-1>=0) 
                sm-=dp[j-i-1];
            ndp[j]=sm;
        }
        swap(dp,ndp);
    }
    return accumulate(all(dp),mint(0));
}
int main() {
    makesieve();
    int n,m; cin >> n >> m;
    vi l(n),r(n);
    for(int i=0;i<n;++i) cin >> l[i] >> r[i];
    mint ans=0;
    for(int j=1;j<=m;++j) {
        if(bad[j]) continue;
        vi ml(n),mr(n);
        for(int i=0;i<n;++i) {
            mr[i] = r[i]/j;
            ml[i] = (l[i]+j-1)/j;
        }
        if(parity[j]) ans-=solve(ml,mr,m/j);
        else ans+=solve(ml,mr,m/j);
    }
    cout << ans << '\n';
}