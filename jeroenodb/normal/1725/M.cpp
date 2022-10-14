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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;

    vector<vector<pi>> g(n*2);
    for(int i=0;i<m;++i) {
        int u,v,w; cin >> u >> v >> w;
        --u,--v;
        g[u].push_back({v,w});
        g[v+n].push_back({u+n,w});
    }
    for(int i=0;i<n;++i) g[i].push_back({i+n,0});
    struct el {
        ll d;
        int at;
        bool operator<(const el& o) const {
            return d>o.d;
        }
    };
    priority_queue<el> pq;
    vector<ll> d(n*2,1e18);
    auto process = [&](el e) {
        if(e.d<d[e.at]) {
            d[e.at]=e.d;
            pq.push(e);
        }
    };
    process({0,0});
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(e.d!=d[e.at]) continue;
        for(auto [to,w] : g[e.at]) {
            process({w+e.d,to});
        }
    }
    for(int i=n+1;i<n*2;++i) {
        if(d[i]==1e18) cout << "-1 ";
        else cout << d[i] << ' ';
    }
    cout << '\n';
}