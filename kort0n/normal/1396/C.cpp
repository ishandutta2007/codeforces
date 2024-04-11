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
ll dp[3][1010000];
ll a[1010000];
ll c[2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, r[3], d;
    cin >> N >> r[0] >> r[1] >> r[2] >> d;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            dp[j][i] = INF;
        }
    }
    dp[0][0] = 0;
    dp[2][0] = 0;
    for(int i = 0; i < N; i++) {
        c[0] = INF;
        c[1] = INF;
        c[1] = min((a[i]+2) * r[0], r[1] + r[0]);
        c[0] = min(a[i] * r[0] + r[2], c[1] + 2 * d);
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                ll newj = j;
                ll newc = dp[j][i] + c[k];
                if(i != 0) newc += d;
                if(j == 2) newc += d;
                if(j == 0 and k == 1) newj = 1;
                if(j == 1 and k == 0) continue;
                if(j == 1 and k == 1) {
                    newj = 0;
                    newc += 2 * d;
                }
                if(j == 2 and k == 1) continue;
                chmin(dp[newj][i+1], newc);
                if(i != N - 1) chmin(dp[2][i+1], newc);
                //cerr << i << " " << j << " " << k << " " << newj << " "<< dp[j][i] << " " << newc << endl;
            }
        }
    }
    /*
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < 3; j++) {
            cerr << dp[j][i] << " ";
        }
        cerr << endl;
    }
    */
    ll ans = INF;
    chmin(ans, dp[0][N]);
    chmin(ans, dp[2][N]);
    cout << ans << endl;
    return 0;
}