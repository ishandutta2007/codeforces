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
ll H, W, K;
ll dp[11][500][500];
ll cost[500][500][4];
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
ll ans[500][500];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    if(K % 2 == 1) {
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                if(w != 0) cout << " ";
                cout << -1;
            }
            cout << endl;
        }
        return 0;
    }
    for(int t = 1; t <= 10; t++) {
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                dp[t][h][w] = INF;
            }
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W-1; w++) {
            int c;
            cin >> c;
            cost[h][w][2] = c;
            cost[h][w+1][3] = c;
        }
    }
    for(int h = 0; h < H - 1; h++) {
        for(int w = 0; w < W; w++) {
            int c;
            cin >> c;
            cost[h][w][0] = c;
            cost[h+1][w][1] = c;
        }
    }
    for(int t = 0; t < K / 2; t++) {
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                for(int k = 0; k < 4; k++) {
                    int newh = h + dh[k];
                    int neww = w + dw[k];
                    if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                    chmin(dp[t+1][newh][neww], dp[t][h][w] + 2 * cost[h][w][k]);
                }
            }
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(w != 0) cout << " ";
            cout << dp[K/2][h][w];
        }
        cout << endl;
    }
    return 0;
}