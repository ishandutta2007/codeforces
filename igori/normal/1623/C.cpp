#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long L = 0, R = 1e9;
    while (L + 1 < R)
    {
        long long M = (L + R) / 2;
        vector<long long> p(n);
        for (int i = n - 1; i >= 2; i--)
        {
            long long cnt = a[i] + p[i];
            long long third_take = min((cnt - M) / 3, a[i] / 3);
            p[i - 1] += third_take;
            p[i - 2] += 2 * third_take;
        }
        int ok = 1;
        for (int i = 0; i < n; i++)
        {
            if (p[i] + a[i] < M)
                ok = 0;
        }
        if (ok) L = M; else R = M;
    }
    cout << L << "\n";
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