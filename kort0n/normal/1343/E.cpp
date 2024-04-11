#include <bits/stdc++.h>
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
ll a[3];

vector<ll> paths[201000];
ll dist[3][201000];
vector<ll> p, psum;
ll N, M;

void bfs(int idx, int s) {
    for(int i = 0; i < N; i++) dist[idx][i] = 1e9;
    dist[idx][s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto to : paths[now]) {
            if(chmin(dist[idx][to], dist[idx][now] + 1)) {
                que.push(to);
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < N; i++) paths[i].clear();
    p.resize(M);
    psum.resize(M + 1);
    for(int i = 0; i < M; i++) cin >> p[i];
    sort(p.begin(), p.end());
    for(int i = 0; i < M; i++) {
        psum[i+1] = psum[i] + p[i];
    }
    for(int i = 0; i < M; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    for(int i = 0; i < 3; i++) {
        bfs(i, a[i]);
    }
    ll ans = 1e18;
    for(int i = 0; i < N; i++) {
        ll tmp1 = dist[1][i];
        ll tmp2 = dist[0][i] + dist[1][i] + dist[2][i];
        if(tmp2 > M) continue;
        ll tmp = psum[tmp1] + psum[tmp2];
        if(chmin(ans, tmp)) {
            //cerr << "update: " << i << " " << tmp1 << " " << tmp2 << " " << ans << endl;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}