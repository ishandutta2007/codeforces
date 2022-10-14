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
const int mxN = 4e5+1, oo = 1e9;
vvi adj;
vi par, grundy;
bitset<mxN> vis;
void dfs(int at) {
    for(int to : adj[at]) {
        adj[to].erase(find(all(adj[to]),at));
        par[to]=at;
        dfs(to);
        grundy[at]^=grundy[to]+1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    par.resize(n), grundy.resize(n), adj.resize(n);
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    vis[0]=true;
    int total=grundy[0];
    int selfloops=0;
    for(int i=0;i<n;++i) {
        int at = i,prev=i;
        if(!vis[at]) total^=grundy[at];
        while(!vis[at]) {
            int p = par[at];
            // tricky business start here
            // dexor
            selfloops++;
            if(at!=i) 
                total^=grundy[at]^(grundy[prev]+1); // correct grundy value
            vis[at]=true;
            if(vis[p]) {
                total^=grundy[at]+1;
            }
            prev = at;
            at = p;
        }
        if((total^(selfloops%2))==0) cout << '2';
        else cout << '1';
    }
}