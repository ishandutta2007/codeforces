#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 100500;

int main()
{

    int n;
    int h[15];

    cin >> n;
    int a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
        ++h[i];
    }

    vector <int> ans;
    while (h[0] > 0)
    {
        h[0] -= b;
        h[1] -= a;
        h[2] -= b;
        ans.pb(1);
    }
    while (h[n - 1] > 0)
    {
        h[n - 1] -= b;
        h[n - 2] -= a;
        h[n - 3] -= b;
        ans.pb(n - 2);
    }

    vector <pii> m;
    for (int i = 1; i <= n - 2; i++)
        m.pb(mp(max(h[i], 0), i));

    if (m.size() == 0)
    {
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << " ";
        return 0;
    }

    if (m.size() == 1)
    {
        while (m[0].first > 0)
        {
            m[0].first -= a;
            ans.pb(m[0].second);
        }
        cout << ans.size() << "\n";
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << " ";
        return 0;
    }

    vector <int> dp[20][20][20];
    vector <int> tmp;

    for (int x = 0; x < 20; x++)
        for (int y = 0; y < 20; y++)
    {
        tmp.assign(100, m[0].second);
        dp[0][x][y] = tmp;
        for (int l = 0; l < 20; l++)
            for (int r = 0; r < 20; r++)
            if (l * a + r * b >= x && l * b + r * a >= y && dp[0][x][y].size() > l + r)
            {
                dp[0][x][y].clear();
                for (int i = 0; i < l; i++)
                    dp[0][x][y].pb(m[0].second);
                for (int i = 0; i < r; i++)
                    dp[0][x][y].pb(m[1].second);
            }
    }

    for (int step = 1; step <= (int) m.size() - 2; step++)
    {
        for (int x = 0; x < 20; x++)
            for (int y = 0; y < 20; y++)
        {
            tmp.assign(1000, m[step].second);
            dp[step][x][y] = tmp;
            for (int l = 0; l < 20; l++)
                for (int r = 0; r < 20; r++)
                if (l * b + r * a >= y
                    && dp[step][x][y].size() > l + r + dp[step - 1][max(m[step - 1].first - l * b, 0)][max(x - l * a - r * b, 0)].size())
            {
                dp[step][x][y] = dp[step - 1][max(m[step - 1].first - l * b, 0)][max(x - l * a - r * b, 0)];
                for (int i = 0; i < l; i++)
                    dp[step][x][y].pb(m[step].second);
                for (int i = 0; i < r; i++)
                    dp[step][x][y].pb(m[step + 1].second);
            }
        }
    }

    cout << ans.size() + dp[(int) m.size() - 2][m[(int) m.size() - 2].first][m[(int) m.size() - 1].first].size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";
    for (int i = 0; i < dp[(int) m.size() - 2][m[(int) m.size() - 2].first][m[(int) m.size() - 1].first].size(); i++)
        cout << dp[(int) m.size() - 2][m[(int) m.size() - 2].first][m[(int) m.size() - 1].first][i] + 1 << " ";

}