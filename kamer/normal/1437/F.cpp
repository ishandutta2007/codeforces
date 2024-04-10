#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

ll pow(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return (a % MOD);
    ll squareRoot = pow(a, n / 2);
    squareRoot = (squareRoot * squareRoot) % MOD;
    if (n % 2 == 0) return squareRoot;
    else return (squareRoot * a) % MOD;
}

ll inv(ll a) {
    return pow(a, MOD - 2);
}

int main(void) {
    vector<ll> fact(5001, 1);
    for (int i = 1; i <= 5000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    vector<ll> invFact(5001);
    for (int i = 0; i <= 5000; i++) {
        invFact[i] = inv(fact[i]);
    }
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<ll>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = vector<ll>(i + 3, 0);
    }
    dp[0][0] = 1;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i + 1; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][1]++;
        int l = i - 1;
        while (l >= 0) {
            if (a[l] > a[i] / 2) l--;
            else break;
        }
        if (l == -1) {
            continue;
        }
        dp[i][1]--;
        ll initSum = 0;
        for (int j = 1; j <= l + 2; j++) {
            initSum = (initSum + dp[l][j - 1] * fact[l - j + 2]) % MOD;
            dp[i][j] = (dp[i][j] + initSum * invFact[l - j + 2]) % MOD;
        }
    }
    cout << dp[n - 1][n] << endl;
}