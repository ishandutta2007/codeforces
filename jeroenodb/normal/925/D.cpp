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
const int mxN = 3e5+1, oo = 1e9;
int dist[mxN],par[mxN];
vi adj[mxN],adj2[mxN];
bitset<mxN> vis;
vi nodes;
pi dfs(int at) {
    vis[at]=true;
    nodes.push_back(at);
    int v=1,e=0;
    for(auto to : adj2[at]) if(!vis[to]) {
        auto [vv,ee] = dfs(to);
        v+=vv,e+=ee+1;
    }
    return {v,e};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    fill_n(dist,n,oo);
    dist[0]=0;
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q; q.push(0);
    vi ans = {oo};
    while(!q.empty()) {
        auto at = q.front(); q.pop();
        if(dist[at]==2) {
            ans = min(ans, {4,0,par[at],at,0,n-1});
        }
        for(auto to : adj[at]) {
            if(dist[at]+1<dist[to]) {
                dist[to] = dist[at]+1;
                q.push(to);
                par[to]=at;
            }
        }
    }
    if(dist[n-1]!=oo) {
        int at = n-1;
        vi res;
        while(at!=0) {
            res.push_back(at);
            at = par[at];
        }
        res.push_back(0);
        res.push_back(dist[n-1]);
        reverse(all(res));
        ans = min(ans,res);
    }
    for(int at=0;at<n;++at) {
        for(int to : adj[at]) {
            if(dist[at]==1 and dist[to]==1) {
                adj2[at].push_back(to);
            }
        }
    }
    if(ans[0]>5) for(int i=0;i<n;++i) {
        if(!vis[i]) {
            nodes.clear();
            auto [v,e] = dfs(i);
            pi best = {oo,oo};
            if(e!=(ll)v*(v-1)/2) {
                for(auto j : nodes)
                    best = min(best, {adj2[j].size(),j});
                int at  = best.second;
                sort(all(nodes));
                sort(all(adj2[at]));
                for(int j : nodes) {
                    if(j!=at and !binary_search(all(adj2[at]),j)) {
                        for(int to : adj2[j]) {
                            if(binary_search(all(adj2[at]),to)) {
                                // good
                                ans = min(ans, {5,0,at,to,j,at,n-1});
                                goto answering;
                            }
                        }
                    }
                }
            } 
        }
    }
    answering: if(ans[0]==oo) cout << "-1\n";
    else {
        cout << ans[0] << '\n';
        ans.erase(ans.begin());
        for(auto i : ans) cout << i+1 << ' ';
        
    }
}