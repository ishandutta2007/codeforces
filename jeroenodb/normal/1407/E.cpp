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
const int mxN = 5e5+1, oo = 1e9;
vector<pair<int,bool>> adj[mxN];
int dist[2][mxN];
const int k = 4;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=0;i<m;++i) {
        int u,v,t; cin >> u >> v >> t,--u,--v;
        adj[v].emplace_back(u,t);
    }
    for(int i=0;i<2;++i) fill(dist[i],dist[i]+n,oo);
    dist[0][n-1]=dist[1][n-1]=0;
    vi q = {n-1};
    for(int i=0;i<(int)q.size();++i) {
        int at = q[i], tmp = max(dist[0][at],dist[1][at])+1;
        for(auto [to,color] : adj[at]) {
            
            int old = max(dist[0][to],dist[1][to]);
            if(dist[color][to]>tmp) {
                dist[color][to]=tmp;
                int nw = max(dist[0][to],dist[1][to]);
                if(nw<old) {
                    q.push_back(to);
                }
            }
        }
    }
    int ans = max(dist[0][0],dist[1][0]);
    if(ans==oo) cout << "-1\n";
    else cout << ans << '\n';
    for(int i=0;i<n;++i) {
        cout << (dist[0][i]<=dist[1][i]);
    }
}