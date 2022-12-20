#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e6 + 1;
const long long mod = 998244353;
int ep[N], dp[N][2];

long long solve(vector <int> v, long long k) {
    if (v[0] < 0) {
        dp[0][0] = 1;
        dp[0][1] = 1;
        ep[0] = 1;
    } else {
        ep[0] = v[0];
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    for (int i = 1; i < v.size(); ++i)
    if (v[i] < 0) {
        ep[i] = ep[i - 1];
        dp[i][0] = ((k - 2) * dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][1] = ((k - 1) * dp[i - 1][0]) % mod;
    } else {
        dp[i][0] = 0;
        ep[i] = v[i];
        if (ep[i - 1] == v[i])
            dp[i][1] = ((k - 1) * dp[i - 1][0]) % mod;
        else
            dp[i][1] = ((k - 2) * dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    int n = v.size() - 1;
    return ((k - 1) * dp[n][0] + dp[n][1]) % mod;
}

vector <int> v1, v2;

int main() {
    int i, j, k, n, q, t, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    vector <int> v1, v2;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        if (i % 2 == 1)
            v1.push_back(j);
        else
            v2.push_back(j);
    }
    cout << (solve(v1, k) * solve(v2, k)) % mod;
}