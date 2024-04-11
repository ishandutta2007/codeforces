#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll n;
vector<ll> pathes[200500];
ll dist[205000];
ll SIZE[200500];
ll dp[200500];

void dfs(int now, int from) {
    SIZE[now]++;
    for(int i = 0; i < pathes[now].size(); i++) {
        int to = pathes[now][i];
        if(to == from) continue;
        dist[to] = dist[now] + 1;
        dfs(to, now);
        SIZE[now] += SIZE[to];
    }
}

void propagate(int now, int from) {
    for(int i = 0; i < pathes[now].size(); i++) {
        int to = pathes[now][i];
        if(to == from) continue;
        dp[to] = dp[now] - SIZE[to] + (n - SIZE[to]);
        propagate(to, now);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        pathes[u].push_back(v);
        pathes[v].push_back(u);
    }
    dist[1] = 0;
    dfs(1, -1);
    for(int i = 1; i <= n; i++) {
        dp[1] += dist[i] + 1;
    }
    cerr << dp[1] << endl;
    propagate(1, -1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        chmax(ans, dp[i]);
        //cerr << i << " " << dp[i] << endl;
    }
    cout << ans << endl;
    return 0;
}