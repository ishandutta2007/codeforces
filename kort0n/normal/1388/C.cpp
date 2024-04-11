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

vector<ll> edge[105000];
ll h[105000], p[105000];
ll N, M;
bool clear;
ll happy[105000];
ll unhappy[105000];

void dfs(int now, int from) {
    for(auto to : edge[now]) {
        if(to == from) continue;
        dfs(to, now);
        happy[now] += happy[to];
        unhappy[now] += unhappy[to];
    }
    unhappy[now] += p[now];
    ll delta = h[now] - (happy[now] - unhappy[now]);
    if(delta < 0) clear = false;
    if(delta % 2 != 0) clear = false;
    happy[now] += delta / 2;
    unhappy[now] -= delta / 2;
    if(happy[now] < 0 or unhappy[now] < 0) clear = false;
}

void solve() {
    clear = true;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        edge[i].clear();
        happy[i] = 0;
        unhappy[i] = 0;
    }
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    dfs(0, -1);
    if(clear) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}