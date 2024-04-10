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
int main() {
    int n; cin >> n;
    // can't be too unbalanced?
    vi h(n+1);
    for(int i=2;i<=n;++i) {
        h[i] = i-1 + h[i/2] + h[(i-1)/2];
    }
    vector<mint> dp(n+1),dp2(n+1);
    dp[0]=1,dp2[0]=1;
    dp2[1]=1;
    int mx=0,ptwo=1;
    vi bs = {1,1};
    for(int i=2;i<=n;++i) {
        while(bs.back()<i) {
            int l = bs.size();
            if(l%2==0) bs.push_back(bs[l-1]*2);
            else bs.push_back(bs[l-1]*2-1);
        }
        if(bs.back()-i<100) for(int j=0;j<i;++j) if(h[j]+h[i-j-1]+i-1==h[i]) {
            if(j%2==0) {
                // i am odd
                dp2[i]+=dp[j]*dp[i-j-1];
            } else {
                dp[i]+=dp2[j]*dp[i-j-1];
            }
        }
    }
    for(int i=0;i<=n;++i) dp[i]+=dp2[i];
    // bool last=false;
    // for(int i=0;i<n;++i) {
    //     auto cur = dp[i]+dp2[i]==0;
    //     if(last!=cur) cout << i << ' ';
    //     last = cur;
    // }
    // debug(bs);
    cout << dp[n];
}