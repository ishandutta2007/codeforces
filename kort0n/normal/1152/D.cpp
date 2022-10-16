#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
ll dp[1005][1005];

ll DP(ll a, ll b) {
    if(a < 0 || b < 0) return 0;
    if(a > b) return 0;
    if(dp[a][b] != 0) return dp[a][b];
    //ll val1 = DP(a-1, b) + DP(a - 1, b - 1) + DP(a, b - 2);
    ll val1 = DP(a-1, b);
    if(a<b) {
        val1 += DP(a-1, b-1) + DP(a, b-2) + 1;
    }
    //ll val2 = DP(a, b-1) + DP(a-2, b) + DP(a-1, b-1);
    ll val2 = DP(a, b-1);
    if(a > 0){
        val2 += DP(a-1, b-1) + DP(a-2, b) + 1;
    }
    return dp[a][b] = max(val1, val2) % mod;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    dp[0][1] = 1;
    cout << DP(N, N) << endl;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            cerr << i << " " << j << " " << DP(i, j) << endl;
        }
    }
    return 0;
}