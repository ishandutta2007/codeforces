#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
#define rep(i,n) for(int i=0;i<n;++i)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 101, K = 22;
const long long MD = 1e9+7;
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
mint dp[mxN][K][K];
vi adj[mxN];
int k;
// dp[at][nearest black to root][farthest bad]
void dfs(int at, int from) {
    auto c = dp[at];
    c[0][k+1]=1;
    c[k+1][0]=1; // white
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        mint ndp[K][K] = {}; // with farthest bad
        auto ct = dp[to];
        rep(i,k+2) rep(j,k+2) if(c[i][j]!=0) rep(e,k+2) rep(f,k+2) if(ct[e][f]!=0) {
            int nearest = min({i,e+1,k+1});
            int farthest = k+1;
            if(j!=k+1 and e+1+j>k) farthest = j;
            bool farinsub=false;
            if(f!=k+1 and f+1+i>k and (f+1>farthest or farthest==k+1)) 
                farthest = f+1,farinsub=true;
            if(farinsub and farthest==k+1) 
                continue;
            ndp[nearest][farthest]+=c[i][j]*ct[e][f];
        }
        memcpy(c[0],ndp[0],sizeof(ndp));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> k;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v),adj[v].push_back(u);
    }
    dfs(1,0);
    mint res=0;
    for(int i=0;i<k+2;++i) {
        res+=dp[1][i][k+1];
    }
    cout << res << endl;
}