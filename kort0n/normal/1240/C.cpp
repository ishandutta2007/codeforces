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
ll dp[2][500500];
vector<l_l> pathes[500500];
ll N, K;

void dfs(int now, int from) {
    dp[0][now] = 0;
    dp[1][now] = 0;
    ll base = 0;
    vector<ll> plus;
    for(auto to : pathes[now]) {
        if(to.first == from) continue;
        dfs(to.first, now);
        base += dp[0][to.first];
        plus.push_back(dp[1][to.first] + to.second - dp[0][to.first]);
    }
    sort(plus.begin(), plus.end(), greater<ll>());
    dp[0][now] = base;
    dp[1][now] = base;
    for(int i = 0; i < min((ll)plus.size(), K - 1); i++) {
        dp[1][now] += max(0LL, plus[i]);
    }
    for(int i = 0; i < min((ll)plus.size(), K); i++) {
        dp[0][now] += max(0LL, plus[i]);
    }
}

void solve() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) pathes[i].clear();
    for(int i = 1; i <= N - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        pathes[u].push_back({v, w});
        pathes[v].push_back({u, w});
    }
    dfs(1, -1);
    cout << max(dp[0][1], dp[1][1]) << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--) solve();
    return 0;
}