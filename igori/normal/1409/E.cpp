#include <bits/stdc++.h>

using namespace std;

const int INF = 88888888;
const int N = 203;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    int ddd;
    for (int i = 0; i < n; i++) cin >> ddd;
    sort(x.begin(), x.end());
    vector<int> le(n), ri(n);
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        while (j + 1 < n && x[j + 1] <= x[i] + k) j++;
        ri[i] = j - i + 1;
    }
    j = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j - 1 >= 0 && x[i] - k <= x[j - 1]) j--;
        le[i] = i - j + 1;
    }
    for (int i = n - 2; i >= 0; i--) ri[i] = max(ri[i], ri[i + 1]);
    for (int i = 1; i < n; i++) le[i] = max(le[i], le[i - 1]);
    int ans = 0;
    for (int i = 0; i + 1 < n; i++)
    {
        ans = max(ans, le[i] + ri[i + 1]);
    }
    ans = max(ans, le[n - 1]);
    ans = max(ans, ri[0]);
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}