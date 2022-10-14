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
    n++;
    vector<mint> dp(n+1),dp2(n+1);
    // dp[n] = number of non isomorphic binary trees with depth <= n
    // dp2[n] = number of non isomorphic binary trees with max depth = n.
    // depth = max number of nodes of any root to leaf path in the binary tree.
    dp[0]=1; // empty tree
    dp2[0]=1; // empty tree
    const mint halve = mint(1)/2;
    for(int i=1;i<=n;++i) {
        dp[i] = 1; // empty tree
        dp[i] += (dp[i-1]*(dp[i-1]+1))*halve; // all combinations of <=i-1 depth trees hanging underneath!
        dp2[i] = dp[i]-dp[i-1];
    }
    // if three trees hanging off root.
    mint one=dp2[n-1]*dp[n-2]*(dp[n-2]+1)/2; // one subtree has maximal depth
    mint two=dp2[n-1]*(dp2[n-1]+1)*halve*dp[n-2]; // two subtrees have depth of n-1
    mint three = dp2[n-1]*(dp2[n-1]+1)*(dp2[n-1]+2)/6; // all 3 subtrees have depth of n-1
    
    mint ans = (one+two+three)*2 -1;
    // need all trees which don't all connect to root.
    for(int i=1;i<n;++i) {
        // don't count the degenerate tree which is a path on the left side
        ans+=(dp2[i]-1)*(dp2[n-i]-dp2[n-i-1]);
        // make sure the right side is a degree 3 vertex, so no double counting.
    }
    cout << ans << '\n';
}