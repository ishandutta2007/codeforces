#pragma GCC optimize("Ofast")
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
const int mxN =600;
const ll oo = 1e18;
ll d[mxN][mxN], dp[mxN][mxN];
void minset(ll& a, ll b) {
    a = min(a,b);
}
void maxset(ll&a, ll b) {
    a = max(a,b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    struct edge{
        int a,b,w;
    };
    vector<edge> edges(m);
    for(int i=0;i<n;++i) {
        fill(d[i],d[i]+n,oo);
        d[i][i] = 0;
    }
    for(int i=0;i<m;++i) {
        int a,b,w; cin >> a >> b >> w;
        --a,--b;
        d[a][b] = d[b][a] = w;
        edges[i] = {a,b,w};
    }
    for(int j=0;j<n;++j)
        for(int i=0;i<n;++i)
            for(int k=0;k<n;++k)
                minset(d[i][k], d[i][j]+d[j][k]);
    int q; cin >> q;
    while(q--) {
        int a,b,w; cin >> a >> b >> w;
        --a,--b;
        dp[a][b] = dp[b][a] = w;
    }
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j) {
                maxset(dp[i][j], dp[i][k]-d[j][k]);
                dp[j][i] = dp[i][j];
            }
    int ans = 0;
    for(auto& e : edges) {
        if(dp[e.a][e.b]>=e.w) {
            ans++;
        }
    }
    cout << ans << '\n';
}