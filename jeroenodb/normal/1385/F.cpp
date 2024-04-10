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
void solve() {
    int n,k;cin >> n >> k;
    vvi adj(n);
    vi deg(n), leafs(n);
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    vector<bool> isleaf(n);
    for(int i=0;i<n;++i) if(deg[i]==1) {
        leafs[adj[i][0]]++;
        isleaf[i]=true;
    }
    queue<int> q;
    for(int i=0;i<n;++i) if(leafs[i]>=k) q.push(i);
    int ans=0;
    while(!q.empty() and ans<n-1) {
        int at = q.front(); q.pop();
        int tmp = leafs[at]/k;
        ans+=tmp;
        leafs[at]-=tmp*k;
        deg[at]-=tmp*k;
        if(deg[at]==1) {
            isleaf[at]=true;
            for(auto to : adj[at]) if(!isleaf[to]) {
                if(++leafs[to]==k) {
                    q.push(to);
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}