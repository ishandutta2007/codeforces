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
ll l[201000][2];
vector<ll> edges[201000];
ll N;
ll dp[201000][2];

void dfs(int now, int p) {
    vector<int> children;
    for(auto c : edges[now]) {
        if(c == p) continue;
        children.push_back(c);
        dfs(c, now);
    }
    for(int i = 0; i < 2; i++) {
        ll val = l[now][i];
        for(auto c : children) {
            ll tmp = 0;
            for(int j = 0; j < 2; j++) {
                chmax(tmp, dp[c][j] + abs(l[c][j] - l[now][i]));
            }
            dp[now][i] += tmp;
        }
    }
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        dp[i][0] = 0;
        dp[i][1] = 0;
        edges[i].clear();
        cin >> l[i][0] >> l[i][1];
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(0, -1);
    ll ans = max(dp[0][0], dp[0][1]);
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