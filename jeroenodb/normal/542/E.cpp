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
const int mxN = 1e3+1, oo = 1e9;
bitset<mxN> vis,col;
vi adj[mxN];
void bfsBi(int n) {
    for(int s=0;s<n;++s)if(!vis[s]){
        vi q = {s};
        vis[s]=true;
        for(int i=0;i<(int)q.size();++i) {
            auto at =q[i];
            for(auto to : adj[at]) {
                if(!vis[to]) {
                    vis[to]=true, col[to]=!col[at];
                    q.push_back(to);
                } 
                if(col[to]==col[at]) {
                    cout << "-1\n";
                    exit(0);
                }
            }
        }
    }
}
auto bfs(int s) {
    vis.reset();
    vector<pi> q = {{s,0}};
    vis[s]=true;
    for(int i=0;i<(int)q.size();++i) {
        auto [at,d] =q[i];
        for(auto to : adj[at]) if(!vis[to]) {
            vis[to]=true;
            q.push_back({to,d+1});
        }
    }
    return q;
}
int main() {
    int n,m; cin >> n >> m;
    while(m--) {
        int a,b; cin >> a >> b,--a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfsBi(n);
    int ans=0;
    vector<bool> used(n);
    for(int i=0;i<n;++i) if(!used[i]) {
        auto q = bfs(i);
        for(auto [at,d] : q) used[at]=true;
        int best=0;
        for(auto [at,d] : q) {
            best = max(best,bfs(at).back().second);
        }
        ans+=best;
    }
    cout << ans << '\n';


}