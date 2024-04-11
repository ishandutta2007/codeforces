#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;

ll dist[1005][1005];
vector<l_l> edges[1005];
ll N, M, K;
ll u[1005], v[1005];

void Dijkstra(ll s) {
    for(ll i = 0; i < N; i++) dist[s][i] = INF;
    dist[s][s] = 0;
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    que.push({0, s});
    while(!que.empty()) {
        auto tmp = que.top();
        que.pop();
        ll from = tmp.second;
        ll fromc = tmp.first;
        if(dist[s][from] != fromc) continue;
        for(auto e : edges[from]) {
            ll to = e.first;
            ll newc = fromc + e.second;
            if(chmin(dist[s][to], newc)) {
                que.push({newc, to});
            }
        }
    }
}

ll ans = INF;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    for(int i = 0; i < K; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }
    for(int i = 0; i < N; i++) Dijkstra(i);
    for(int i = 0; i < N; i++) {
        for(auto e : edges[i]) {
            ll a = i;
            ll b = e.first;
            ll c = e.second;
            ll nowans = 0;
            for(int i = 0; i < K; i++) {
                ll tmp = dist[u[i]][v[i]];
                chmin(tmp, dist[u[i]][a] + dist[b][v[i]]);
                chmin(tmp, dist[u[i]][b] + dist[a][v[i]]);
                nowans += tmp;
            }
            chmin(ans, nowans);
        }
    }
    cout << ans << endl;
    return 0;
}