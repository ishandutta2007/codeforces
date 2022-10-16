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
int dp[2001][2001];
int a[2001];
int N, H, L, R;
int main() {
    cin >> N >> H >> L >> R;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= H; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < H; j++) {
            int to = (j + a[i] - 1) % H;
            chmax(dp[i+1][to], dp[i][j]);
            if(L <= to and to <= R) {
                chmax(dp[i+1][to], dp[i][j] + 1);
            }
            to = (to + 1) % H;
            chmax(dp[i+1][to], dp[i][j]);
            if(L <= to and to <= R) {
                chmax(dp[i+1][to], dp[i][j] + 1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < H; i++) {
        chmax(ans, dp[N][i]);
    }
    cout << ans << endl;
    return 0;
}