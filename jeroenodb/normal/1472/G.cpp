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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        vvi adj(n);
        while(m--) {
            int a,b; cin >> a >> b;--a,--b;
            adj[a].push_back(b);
        }
        vi dist(n,oo);
        dist[0] = 0;
        vector<int> q; q.push_back(0); q.reserve(n);
        for(int i=0;i<n;++i) {
            int at=q[i];
            for(int to: adj[at]) {
                if(dist[to]==oo) {
                    dist[to] = dist[at]+1;
                    q.push_back(to);
                }
            }
        }
        vi dp(dist);
        for(int i=0;i<n;++i) {
            for(int to: adj[i]) {
                dp[i] = min(dp[i],dist[to]);
            }
        }
        vi ans(dp);
        vector<bool> visited(n);
        function<int(int)> dfs = [&adj, &ans,&dist,&visited,&dfs](int at) {
            visited[at]=true;
            for(int to: adj[at]) {
                if(dist[to]>dist[at]) {
                    if(visited[to]) {
                        ans[at] = min(ans[to],ans[at]);
                    } else 
                        ans[at] = min(dfs(to),ans[at]);
                }
            }
            return ans[at];
        };
        dfs(0);
        cout << ans << '\n';
    }
}