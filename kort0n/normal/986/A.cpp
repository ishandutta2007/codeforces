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
ll N, M, K, S;
ll a[105000];
ll dist[105][105000];
vector<ll> edges[105000];

void BFS(int idx) {
    for(int i = 0; i < N; i++) dist[idx][i] = INF;
    queue<int> que;
    for(int i = 0; i < N; i++) {
        if(a[i] != idx) continue;
        dist[idx][i] = 0;
        que.push(i);
    }
    while(!que.empty()) {
        auto from = que.front();
        que.pop();
        for(auto to : edges[from]) {
            if(chmin(dist[idx][to], dist[idx][from] + 1)) {
                que.push(to);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K >> S;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i = 0; i < K; i++) {
        BFS(i);
    }
    for(int i = 0; i < N; i++) {
        vector<ll> v;
        for(int idx = 0; idx < K; idx++) {
            v.push_back(dist[idx][i]);
        }
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i < S; i++) {
            ans += v[i];
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}