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
ll N, K;
vector<ll> paths[201000];
ll dp[201000];
ll dp1[201000][5];
ll dp2[201000][5];
ll ans = 0;

void dfs1(int now, int from) {
    dp1[now][0] = 1;
    for(auto to : paths[now]) {
        if(to == from) continue;
        dfs1(to, now);
        dp[now] += dp[to];
        dp[now] += dp1[to][0];
        for(int k = 0; k < K; k++) {
            dp1[now][(k+1)%K] += dp1[to][k];
        }
    }
    for(int k = 0; k < K; k++) {
        dp2[now][k] = dp1[now][k];
        //cerr << now << " " << k << " " << dp1[now][k] << endl;
    }
    //cerr << "dp: " << now << " " << dp[now] << endl;
}

void dfs2(int now, int from) {
    //cerr << now << " " << ans << endl;
    //ans += dp[now];
    if(from != -1) {
        ll tmp = dp[from] - dp[now];
        tmp -= dp2[now][0];
        tmp += dp2[from][0];
        tmp -= dp2[now][(K-1+K)%K];
        dp[now] += tmp;
        vector<ll> v(K);
        for(int k = 0; k < K; k++) {
            v[k] = dp2[now][k] + dp2[from][(k-1+K)%K];
            v[k] -= dp2[now][(k-2+K+K)%K];
        }
        for(int k = 0; k < K; k++) {
            dp2[now][k] = v[k];
        }
    }
    ans += dp[now];
    //cerr << now << " " << ans << endl;
    for(auto to : paths[now]) {
        if(to == from) continue;
        dfs2(to, now);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    cout << ans / 2 << endl;
    return 0;
}