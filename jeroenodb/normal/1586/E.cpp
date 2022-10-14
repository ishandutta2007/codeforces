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
const int mxN = 3e5+2, oo = 1e9;
vi adj[mxN];
bitset<mxN> vis;
int par[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;

    for(int i=0;i<m;++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    {
    queue<int> q;
    q.push(1);
    vis.reset();
    while(!q.empty()) {
        int at = q.front(); q.pop();
        for(int to : adj[at]) if(!vis[to]) {
            par[to]=at;
            vis[to]=true;
            q.push(to);
        }
    }
    }
    vi deg(n+1);
    int q; cin >> q;
    vector<pi> qs(q);
    for(auto& [a,b]: qs) {
        cin >> a >> b;
        deg[a]++,deg[b]++;
    }
    int odd=0;
    for(int i=1;i<=n;++i) if(deg[i]%2==1) {
        odd++;
    }
    if(odd) cout << "NO\n" << odd/2 << '\n';
    else {
        cout << "YES\n";
        for(auto [a,b] : qs) {
            // bfs
            vi res;
            int at = a;
            while(at!=1) {
                res.push_back(at);
                at=par[at];
            }

            res.push_back(1);
            vi res2;
            at = b;
            while(at!=1) {
                res2.push_back(at);
                at=par[at];
            }
            
            res2.push_back(1);
            int prev=0;
            while(!res.empty() and !res2.empty() and res.back()==res2.back()) {
                prev = res.back();
                res.pop_back();
                res2.pop_back();
            }
            reverse(all(res2));
            cout << res.size()+res2.size()+1 << '\n' << res  << ' ' <<  prev << ' ' << res2 << '\n';
        }
    }
    
}