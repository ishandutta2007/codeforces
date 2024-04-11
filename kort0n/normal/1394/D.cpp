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
ll dp[200100][3];
ll t[201000];
ll h[200100];
ll N;
vector<ll> edges[201000];
ll p[201000];

void dfs(ll now) {
    vector<ll> children;
    for(auto to : edges[now]) {
        if(to == p[now]) continue;
        p[to] = now;
        dfs(to);
        children.push_back(to);
    }
    for(int i = 0; i < 3; i++) {
        dp[now][i] = INF;
        if(i == 0 and p[now] != -1) continue;
        if(i != 0 and p[now] == -1) continue;
        if(i == 1 and h[now] > h[p[now]]) continue;
        if(i == 2 and h[now] < h[p[now]]) continue;
        __int128_t base = 0;
        vector<__int128_t> v;
        for(auto tmp : children) {
            base += dp[tmp][1];
            v.push_back(dp[tmp][2] - dp[tmp][1]);
        }
        sort(v.begin(), v.end());
        vector<__int128_t> vsum(1);
        for(auto tmp : v) {
            __int128_t val = tmp + vsum.back();
            vsum.push_back(val);
        }
        for(int j = 0; j < vsum.size(); j++) {
            __int128_t val = vsum[j] + base;
            ll IN = j;
            ll OUT = v.size() - j;
            if(i == 1) IN++;
            if(i == 2) OUT++;
            val += max(IN, OUT) * t[now];
            if(val > (__int128_t)INF) continue;
            //cerr << now << " " << i << " " << j << " " << val << endl;
            chmin(dp[now][i], (ll)val);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> t[i];
    for(int i = 0; i < N; i++) cin >> h[i];
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    p[0] = -1;
    dfs(0);
    ll ans = dp[0][0];
    cout << ans << endl;
    return 0;
}