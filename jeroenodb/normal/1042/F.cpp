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
const int mxN = 1e6+1, oo = 1e9;
int dd=0,k;
vi adj[mxN],cand[mxN];
bitset<mxN> vis;
int ans=0;
int dfs(int at) {

    vis[at]=true;
    if(adj[at].size()==1) return 0;
    for(int to : adj[at]) if(!vis[to]) {
        dd++;
        cand[at].push_back(dfs(to)+1);
        dd--;
    }
    sort(all(cand[at]));
    auto& v = cand[at];
    while(v.size()>=2 and v[v.size()-2]+v.back()>k) {
        v.pop_back();
        ans++;
    }
    return v.back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n >> k;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        --u,--v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int root=-1;
    for(int i=0;i<n;++i) if(adj[i].size()>1) root=i;
    assert(root!=-1);
    dfs(root);
    // Nu is het een array probleem
    cout << ans+1 << '\n';
}