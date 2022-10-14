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
const long long MD = (int)1e9 + 7;
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
const int mxF = 2e6+2;
mint fact[mxF], ifact[mxF];
mint ncr(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
const int mxS = 5001;
mint dp[mxS][mxS];
void precomp() {
    fact[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
    dp[0][0]=1;

    for(int n=0;n+1<mxS;++n) {
        for(int k=1;k<=n+1;++k) {
            dp[n+1][k] = dp[n][k]*k + dp[n][k-1];
        }
    }
}

void solve() {
    int n,m=2,k; cin >> n >> k;
    // j unique values
    // Need at least one of each
    // j^k - ncr(j,j-1) (j-1)^k + ncr(j,j-2)*(j-2)^k) 
    // linear time is easy, but too bad
    // dp[k][j] = dp[k-1][j]*j + dp[k-1][j-1]*(K-j+1)  (need to give my own coefficients?)
    mint prob = mint((m+1)/2)/m;
    mint pw=1, perm=1, ans=0;
    for(int j=1;j<=min(n,k);++j) {
        pw*=prob;
        perm*=n-j+1;
        auto tmp = dp[k][j];
        ans+=tmp*pw*perm;
    }
    cout << ans*(mint(m)^n) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precomp();
    // int t; cin >> t;
    // E[X^c]
    // X = I_1 + I_2 + I_3 + ... + I_n
    // Split and use linearity of expectation
    // How many ways to get k unique values?
    // k! * number of ways without switchings = stars and bars
    // n^C
    int t=1;
    while(t--) {
        solve();
    }
}