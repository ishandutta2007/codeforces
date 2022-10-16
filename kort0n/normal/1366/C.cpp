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
ll A[1000][1000];
void solve() {
    ll H, W;
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }
    ll ans = 0;
    for(ll sum = 0; sum < H + W; sum++) {
        ll rest = H + W - 2 - sum;
        if(rest <= sum) continue;
        ll num[2] = {0, 0};
        for(int h = 0; h < H; h++) {
            ll w = sum - h;
            if(0 <= w and w < W) {
                num[A[h][w]]++;
            }
        }
        for(int h = 0; h < H; h++) {
            ll w = rest - h;
            if(0 <= w and w < W) {
                num[A[h][w]]++;
            }
        }
        ans += min(num[0], num[1]);
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