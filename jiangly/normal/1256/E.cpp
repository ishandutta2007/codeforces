#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1E9;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for (int &i : a)
        cin >> i;
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) {return a[i] < a[j];});
    vector<int> dp(n + 1, INF), k(n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 3; j <= 5 && j <= i + 1; ++j) {
            if (dp[i + 1] > dp[i - j + 1] + a[p[i]] - a[p[i - j + 1]]) {
                dp[i + 1] = dp[i - j + 1] + a[p[i]] - a[p[i - j + 1]];
                k[i + 1] = j;
            }
        }
    }
    cout << dp[n] << " ";
    int total = 0;
    vector<int> group(n);
    for (int i = n; i > 0; ) {
        ++total;
        for (int j = i - k[i]; j < i; ++j)
            group[p[j]] = total;
        i -= k[i];
    }
    cout << total << "\n";
    for (int i = 0; i < n; ++i)
        cout << group[i] << " \n"[i == n - 1];
    return 0;
}