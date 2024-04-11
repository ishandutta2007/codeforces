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
vector<ll> children[200100];
ll p[200010];
vector<ll> paths[200010];
l_l dp[200100];
ll ans;
vector<ll> a, b, c;
void dfs2(int now) {
    for(auto to : children[now]) {
        dfs2(to);
        dp[now].first += dp[to].first;
        dp[now].second += dp[to].second;
    }
    if(b[now] == 0 and c[now] == 1) dp[now].first++;
    if(b[now] == 1 and c[now] == 0) dp[now].second++;
    ll num = min(dp[now].first, dp[now].second);
    ans += 2 * num * a[now];
    dp[now].first -= num;
    dp[now].second -= num;
}
void dfs(int now) {
    for(auto to : paths[now]) {
        if(to == p[now]) continue;
        p[to] = now;
        children[now].push_back(to);
        chmin(a[to], a[now]);
        dfs(to);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    a.resize(N);
    b.resize(N);
    c.resize(N);
    ll sumb = 0;
    ll sumc = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
        sumb += b[i];
        sumc += c[i];
    }
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    if(sumb != sumc) {
        cout << -1 << endl;
        return 0;
    }
    p[0] = -1;
    dfs(0);
    dfs2(0);
    cout << ans << endl;
    return 0;
}