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
using  mint = mdint<MD>;
const int mxN = 300+3, oo = 1e9;
mint dp[mxN][2][mxN], ptwo[mxN];
int sz[mxN], r,n;
vi adj[mxN];
#define rep(i,n) for(int i=0;i<n;++i)
void dfs(int at, int from) {
    // init empty subtree
    auto cur = dp[at];
    cur[0][0] = 1,cur[1][0]=1; 
    //not available      available
    sz[at]=1;
    // For each child, calculate DP and recalculate own DP.
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        auto old = dp[to];
        mint nw[2][mxN] = {};
        int nwsz = min(r+1,max(sz[at],sz[to]+1));
        rep(o1,2) rep(o2,2) rep(i,sz[at]) rep(j,sz[to]) {
            auto mul = cur[o1][i]*old[o2][j];
            if(mul==0) continue;
            if(o1==0) {
                // main tree has no uncovered people
                if(o2==0) nw[0][min(i,j+1)]+=mul;
                else if(i+j+1<=r) {
                    nw[0][i]+=mul;
                } else nw[1][j+1] += mul;
            } else {
                if(o2==0) {
                    if(i+j+1<=r) {
                        nw[0][j+1]+=mul;
                    } else nw[1][i]+=mul;
                } else nw[1][max(i,j+1)] += mul;
            }
        }
        sz[at] = nwsz;
        copy_n(nw[0],sz[at],cur[0]);
        copy_n(nw[1],sz[at],cur[1]);
    }
}
int main() {
    ptwo[0]=1;
    for(int i=1;i<mxN;++i) ptwo[i]=ptwo[i-1]*2;
    cin >> n;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mint ans=0;
    mint prev=1;
    for(r=1;r<=n;++r) {
        rep(i,n) rep(j,2) fill_n(dp[i][j],n+2,0);
        dfs(0,0);
        // debug(r);
        mint cur=0;
        rep(j,sz[0]) {
            // debug(j);
            // debug(dp[0][0][j])
            cur+=dp[0][0][j];
        }
        ans+=(cur-prev)*(r-1);
        prev= cur;
    }
    ans+=n;
    ans-=1;
    // sum from -1 to i of P[r=i], subtract out the -1
    // debug(ans);
    cout << (ans)/ptwo[n] << '\n';
}