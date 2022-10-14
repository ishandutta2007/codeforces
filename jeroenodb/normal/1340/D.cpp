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
int tmax;
vi adj[mxN];
vector<pi> ans;
void dfs(int at, int from, int tin) {
    ans.push_back({at,tin});
    adj[at].erase(find(all(adj[at]),from));
    int left = adj[at].size(),t=tin;
    for(int to : adj[at]) {
        if(t==tmax) {
            t=tin-1-left;
            ans.push_back({at,t});
        }
        left--;
        dfs(to,at,++t);
        ans.push_back({at,t});
    }
    if(t!=tin-1) {
        ans.push_back({at,tin-1});
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tmax=adj[1].size();
    for(int i=2;i<=n;++i) tmax = max(tmax,(int)adj[i].size());
    ans.push_back({1,0});
    int t=0;
    for(int to : adj[1]) {
        dfs(to,1,++t);
        ans.push_back({1,t});
    }
    cout << ans.size() << '\n';
    for(auto [a,b] : ans) cout << a << ' ' << b << '\n';
}