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
    int n,m; cin >> n >> m;
    
    vector<basic_string<int>> adj(n);
    vector<array<int,3>> es(m);
    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto bfs = [&](int s, const vi& myd = {}) -> vi {
        vi d(n,oo);
        vector<basic_string<int>> pq(n*2);
        auto process = [&](int at, int dd) {
            if(dd<d[at]) {
                d[at]=dd;
                pq[d[at]].push_back(at);
            }
        };
        if(s!=-1) process(s,0);
        else for(int i=0;i<n;++i) process(i,myd[i]);
        for(int i=0;i<2*n;++i) {
            while(!pq[i].empty()) {
                auto at = pq[i].back();
                pq[i].pop_back();
                if(d[at]!=i) continue;
                for(int to : adj[at]) process(to,d[at]+1);
            }
        }
        return d;
    };
    vi d1 = bfs(0), d2 = bfs(n-1);
    vi d3(n);
    for(int i=0;i<n;++i) d3[i] = d1[i]+d2[i];
    d3 = bfs(-1,d3);
    ll ans = 1e18;
    for(auto& [u,v,w] : es) {
        for(int rep=0;rep<2;++rep) {
            ans = min(ans,w*(2LL+d3[u]));
            ans = min(ans,w*(1LL+d1[u]+d2[v]));
            swap(u,v);
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