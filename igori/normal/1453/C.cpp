#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int d = 0; d < 10; d++)
    {
        int ans = 0;
        vector<int> L(n, n), R(n, -1);
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                if (s[r][c] - '0' == d)
                {
                    L[r] = c;
                    break;
                }
            }
            for (int c = n - 1; c >= 0; c--)
            {
                if (s[r][c] - '0' == d)
                {
                    R[r] = c;
                    break;
                }
            }
        }
        for (int r = 0; r < n; r++)
        {
            ans = max(ans, (R[r] - L[r]) * max(r, n - 1 - r));
        }
        for (int r1 = 0; r1 < n; r1++)
        {
            for (int r2 = 0; r2 < n; r2++)
            {
                if (L[r1] <= R[r1] && L[r2] <= R[r2])
                {
                    int k = r2 - r1;
                    ans = max(ans, k * max(max(R[r1], R[r2]), max(n - 1 - L[r1], n - 1 - L[r2])));
                }
            }
        }
        vector<int> U(n, n), D(n, -1);
        for (int c = 0; c < n; c++)
        {
            for (int r = 0; r < n; r++)
            {
                if (s[r][c] - '0' == d)
                {
                    U[c] = r;
                    break;
                }
            }
            for (int r = n - 1; r >= 0; r--)
            {
                if (s[r][c] - '0' == d)
                {
                    D[c] = r;
                    break;
                }
            }
        }
        for (int c = 0; c < n; c++)
        {
            ans = max(ans, (D[c] - U[c]) * max(c, n - 1 - c));
        }
        for (int c1 = 0; c1 < n; c1++)
        {
            for (int c2 = 0; c2 < n; c2++)
            {
                if (U[c1] <= D[c1] && U[c2] <= D[c2])
                {
                    int k = c2 - c1;
                    ans = max(ans, k * max(max(D[c1], D[c2]), max(n - 1 - U[c1], n - 1 - U[c2])));
                }
            }
        }
        cout << ans << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}