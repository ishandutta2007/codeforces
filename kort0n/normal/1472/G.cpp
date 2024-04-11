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
vector<ll> edges[201000];
ll dist[201000];
ll dp[201000];
ll N, M;
void bfs(int s) {
    for(int i = 0; i < N; i++) dist[i] = INF;
    dist[s] = 0;
    queue<ll> que;
    que.push(s);
    while(que.size()) {
        auto from = que.front();
        que.pop();
        for(auto to : edges[from]) {
            if(chmin(dist[to], dist[from] + 1)) {
                que.push(to);
            }
        }
    }
}
void solve() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        dist[i] = INF;
        dp[i] = INF;
    }
    for(int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
    }
    bfs(0);
    for(ll i = 0; i < N; i++) {
        chmin(dp[i], dist[i]);
        for(auto j : edges[i]) {
            chmin(dp[i], dist[j]);
        }
    }
    vector<ll> a(N);
    for(int i = 0; i < N; i++) a[i] = i;
    sort(a.begin(), a.end(), [&](ll q, ll w) {
        return dist[q] > dist[w];
    });
    for(auto idx : a) {
        for(auto to : edges[idx]) {
            if(dist[to] > dist[idx]) {
                chmin(dp[idx], dp[to]);
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << dp[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}