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
mint dp[mxN][3][11];
vi adj[mxN];
int n,k,x,m;
void dfs(int at,int from=0) {
    auto c = dp[at];
    c[0][0]=k-1;
    c[1][1]=1;
    c[2][0] = m-k;

    for(auto to : adj[at]) if(to!=from) {
        dfs(to,at);
        #define rep(i,n) for(int i=0;i<n;++i)
        mint ndp[3][11] = {};
        auto dt = dp[to];
        
        rep(i,x+1) rep(j,x-i+1) {
            ndp[0][i+j]+=c[0][i]*(dt[0][j]+dt[1][j]+dt[2][j]);
            ndp[1][i+j]+=c[1][i]*(dt[0][j]);
            ndp[2][i+j]+=c[2][i]*(dt[0][j]+dt[2][j]);
        }
        rep(j,3) rep(i,x+1) {
            c[j][i]=ndp[j][i];
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k >> x;
    dfs(1);
    mint res=0;
    for(int i=0;i<3;++i) for(int j=0;j<=x;++j) {
        res+=dp[1][i][j];
    }
    cout << res;
}