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
ll a[105][105];
ll dp[105][105];
ll H, W;

ll f(ll ini) {
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            dp[h][w] = LONG_LONG_MAX;
        }
    }
    if(a[0][0] < ini) return dp[0][0];
    dp[0][0] = a[0][0] - ini;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(dp[h][w] == LONG_LONG_MAX) continue;
            if(h < H - 1) {
                ll delta = a[h+1][w] - (h + 1) - w - ini;
                if(delta >= 0) {
                    chmin(dp[h+1][w], dp[h][w] + delta);
                }
            }
            if(w < W - 1) {
                ll delta = a[h][w+1] - h - (w + 1) - ini;
                if(delta >= 0) {
                    chmin(dp[h][w+1], dp[h][w] + delta);
                }
            }
        }
    }
    return dp[H-1][W-1];
}

void solve() {
    cin >> H >> W;
    vector<ll> v;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cin >> a[h][w];
            v.push_back(a[h][w] - h - w);
        }
    }
    ll ans = LONG_LONG_MAX;
    for(auto i : v) {
        ll tmp = f(i);
        chmin(ans, tmp);
    }
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