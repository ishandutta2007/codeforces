#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
string s[500];
string ans[500];

int ok(int a, int b)
{
    return 0 <= a && a < n && 0 <= b && b < n;
}

int beaten[500][500];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    string g = "";
    for (int i = 0; i < 2 * n - 1; i++) g = g + ".";
    for (int i = 0; i < 2 * n - 1; i++) ans[i] = g;
    for (int dx = - n + 1; dx <= n - 1; dx++)
    {
        for (int dy = - n + 1; dy <= n - 1; dy++)
        {
            if (dx == 0 && dy == 0) continue;
            int oks = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (s[i][j] == 'o' && ok(i + dx, j + dy) && s[i + dx][j + dy] == '.')
                    {
                        oks = 0;
                    }
                }
            }
            if (oks)
            {
                ans[dx + n - 1][dy + n - 1] = 'x';
            }
        }
    }
    int correct = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dx = - n + 1; dx <= n - 1; dx++)
            {
                for (int dy = - n + 1; dy <= n - 1; dy++)
                {
                    if (ok(i + dx, j + dy) && s[i][j] == 'o' && ans[dx + n - 1][dy + n - 1] == 'x')
                    {
                        beaten[i + dx][j + dy] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'x' && beaten[i][j] == 0)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    ans[n - 1][n - 1] = 'o';
    for (int i = 0; i < 2 * n - 1; i++)
    {
        cout << ans[i] << "\n";
    }
}