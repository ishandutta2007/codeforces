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

ll dp[75][75][75][75];
ll A[75][75];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) cin >> A[h][w];
    }
    for(int h = 0; h <= H; h++) {
        for(int w = 0; w <= W; w++) {
            for(int k = 0; k <= 70; k++) {
                for(int l = 0; l <= 70; l++) {
                    dp[h][w][k][l] = -INF;
                }
            }
        }
    }
    dp[0][0][0][0] = 0;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            for(int num = 0; num <= W; num++) {
                for(int l = 0; l <= 70; l++) {
                    if(dp[h][w][num][l] < 0) continue;
                    chmax(dp[h][w+1][num][l], dp[h][w][num][l]);
                    ll newval = dp[h][w][num][l] + A[h][w];
                    chmax(dp[h][w+1][num+1][newval%K], newval);
                }
            }
        }
        for(int k = 0; k <= W / 2; k++) {
            for(int l = 0; l <= K; l++) {
                chmax(dp[h+1][0][0][l], dp[h][W][k][l]);
            }
        }
    }
    ll ans = 0;
    chmax(ans, dp[H][0][0][0]);
    cout << ans << endl;
    return 0;
}