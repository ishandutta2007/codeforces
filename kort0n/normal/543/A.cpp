#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
ll mod = 1000000007;
ll N, M, B;
ll dp[505][505];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> B >> mod;
    dp[0][0] = 1;
    for(int timer = 1; timer <= N; timer++) {
        ll a;
        cin >> a;
        for(int num = 0; num < M; num++) {
            for(int bug = 0; bug <= B - a; bug++) {
                dp[num+1][bug+a] += dp[num][bug];
                dp[num+1][bug+a] %= mod;
            }
        }
    }
    ll ans = 0;
    for(int i = 0; i <= B; i++) {
        ans = (ans + dp[M][i]) % mod;
    }
    cout << ans << endl;
    return 0;
}