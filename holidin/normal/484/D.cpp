#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
vector <int> v;
long long dp[N], a[N];
bool c[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    v.push_back(1);
    for (i = 2; i <= n; ++i) {
        if (a[i] > a[i - 1])
            c[i] = 0;
        else
            c[i] = 1;
        if (c[i] != c[i - 1] || i == 2)
            v.push_back(i);
    }
    dp[0] = 0;
    j = 0;
    for (i = 1; i <= n; ++i) {
        if (j < v.size() - 1 && v[j + 1] <= i)
            ++j;
        for (int t = -1; t <= 1; ++t)
        if (v[j] + t > 0 && v[j] + t <= i)
            dp[i] = max(dp[i], dp[v[j] + t - 1] + abs(a[i] - a[v[j] + t]));
    }
    cout << dp[n];
}