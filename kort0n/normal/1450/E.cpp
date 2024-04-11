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
ll N, M;
ll ansval = -1;
ll ans[205];
ll dist[205];
vector<l_l> edges[205];

void f(ll s) {
    for(int i = 0; i < N; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    queue<ll> que;
    que.push(s);
    while(!que.empty()) {
        auto now = que.front();
        que.pop();
        if(dist[now] < 0) return;
        for(auto tmp : edges[now]) {
            ll to = tmp.first;
            //cerr << now << " " << dist[now] << " " << to << endl;
            if(dist[now] == dist[to]) return;
            ll c = tmp.second;
            if(c == 1) {
                if(chmin(dist[to], dist[now] + 1)) {
                    que.push(to);
                }
                if(chmin(dist[now], dist[to] - 1)) {
                    que.push(now);
                }
            } else if(c == -1) {
                if(chmin(dist[to], dist[now] - 1)) {
                    que.push(to);
                }
                if(chmin(dist[now], dist[to] + 1)) {
                    que.push(now);
                }
            } else if(c == 0) {
                if(chmin(dist[to], dist[now] + 1)) {
                    que.push(to);
                }
                if(chmin(dist[now], dist[to] + 1)) {
                    que.push(now);
                }
            }
        }
    }
    ll maxival = 0;
    for(int i = 0; i < N; i++) {
        chmax(maxival, dist[i]);
    }
    if(chmax(ansval, maxival)) {
        swap(ans, dist);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[a].push_back({b, c});
        edges[b].push_back({a, -c});
    }
    for(int i = 0; i < N; i++) f(i);
    if(ansval == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ansval << endl;
        for(int i = 0; i < N; i++) {
            if(i != 0) cout << " ";
            cout << ans[i];;
        }
        cout << endl;
    }
    return 0;
}