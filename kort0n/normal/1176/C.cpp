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
//const ll mod = 1000000007;
ll num[6];
ll digit[6] = {4, 8, 15, 16, 23, 42};
ll a[505000];
ll dp[505000][6];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 6; j++) {
            dp[i][j] = dp[i-1][j];
            if(a[i] == digit[j]) dp[i][j]++;
        }
        for(int j = 1; j < 6; j++) {
            chmin(dp[i][j], dp[i][j-1]);
        }
    }
    cout << n - 6 * dp[n][5] << endl;
    return 0;
}