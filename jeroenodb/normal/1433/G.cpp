#pragma GCC optimize "Ofast"
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
const int mxN = 1e3+1, oo = 1e9+5;
vector<pi> adj[mxN];
int dist[mxN][mxN];
// void dijkstra(int s, int n) {
//     struct el {
//         int at,d;
//         bool operator<(const el& o) const {return d>o.d;}
//     };
//     priority_queue<el> pq;
//     auto d = dist[s];
//     fill(d,d+n,oo);
//     d[s]=0;
//     pq.push({s,0});
//     while(!pq.empty()) {
//         auto c = pq.top(); pq.pop();
//         if(c.d!=d[c.at]) continue;
//         for(auto [to,w]: adj[c.at]) {
//             w+=c.d;
//             if(w<d[to]) {
//                 d[to]=w;
//                 pq.push({to,w});
//             }
//         }
//     }
// }
int main() {
    int n,m,K; cin >> n >> m >> K;
    for(int i=0;i<n;++i) fill(dist[i],dist[i]+n,oo),dist[i][i]=0;
    vector<array<int,3>> es(m);
    for(auto& [x,y,w] : es) {
        cin >> x >> y >> w,--x,--y;
        dist[x][y]=w;
        dist[y][x]=w;
    }
    // for(int i=0;i<n;++i) dijkstra(i,n);
    for(int j=0;j<n;++j) {
        for(int i=0;i<n;++i) {
            for(int k=0;k<n;++k) {
                dist[i][k] = min(dist[i][k],dist[i][j]+dist[j][k]);
            }
        }
    }
    vector<pi> routes(K);
    for(auto& [a,b]: routes) cin >> a >> b,--a,--b;
    ll ans = (ll)oo*oo;
    for(auto [i,to,w] : es) {
            ll tmp=0;
            for(auto [a,b] : routes) {
                tmp+=min({dist[a][b], dist[a][to]+dist[i][b],dist[a][i]+dist[to][b]});
            }
            ans = min(ans,tmp);
    }
    cout << ans << '\n';
    
}