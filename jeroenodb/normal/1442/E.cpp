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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;

    vvi adj(n);
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans=oo;
    for(int rep=0;rep<2;++rep) {
        int cur=0;
        vi deg(n);
        queue<int> q[3] = {};
        for(int i=0;i<n;++i) {
            deg[i]=adj[i].size();
            if(deg[i]<=1) {
                q[a[i]].push(i);
            }
        }
        int del=0;
        int col=0;
        while(del<n) {
            cur++;
            while(!q[0].empty() or !q[col+1].empty()) {
                auto remove = [&](int at) {
                    del++;
                    for(int to : adj[at]) {
                        if(--deg[to]==1) {
                            q[a[to]].push(to);
                        }
                    }
                };
                if(!q[0].empty()) {
                    auto at = q[0].front(); q[0].pop();
                    remove(at);
                } else {
                    auto at = q[col+1].front(); q[col+1].pop();
                    remove(at);
                }
                
            }
            col=!col;
        }
        ans = min(ans,cur);
        for(auto& i : a) if(i) i^=3;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}