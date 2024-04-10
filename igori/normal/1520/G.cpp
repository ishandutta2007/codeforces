#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cx[4] = {0, 0, 1, -1};
int cy[4] = {1, -1};

void solve()
{
    ll w;
    int r, c;
    cin >> r >> c >> w;
    vector<vector<int> > a(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int> > distS(r, vector<int>(c, -1));
    vector<vector<int> > distF(r, vector<int>(c, -1));
    distS[0][0] = 0;
    vector<pair<int, int> > q = {{0, 0}};
    for (int i = 0; i < q.size(); i++)
    {
        int x = q[i].first, y = q[i].second;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + cx[j], ny = y + cy[j];
            if (0 <= nx && nx < r && 0 <= ny && ny < c)
            {
                if (a[nx][ny] != -1 && distS[nx][ny] == -1)
                {
                    distS[nx][ny] = distS[x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    distF[r - 1][c - 1] = 0;
    q = {{r - 1, c - 1}};
    for (int i = 0; i < q.size(); i++)
    {
        int x = q[i].first, y = q[i].second;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + cx[j], ny = y + cy[j];
            if (0 <= nx && nx < r && 0 <= ny && ny < c)
            {
                if (a[nx][ny] != -1 && distF[nx][ny] == -1)
                {
                    distF[nx][ny] = distF[x][y] + 1;
                    q.push_back({nx, ny});
                }
            }
        }
    }
    long long ans = 1e18;
    if (distF[0][0] != -1) ans = distF[0][0] * w;
    ll to = 1e18, from = 1e18;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] > 0 && distS[i][j] != -1)
            {
                to = min(to, 1ll * distS[i][j] * w + a[i][j]);
            }
            if (a[i][j] > 0 && distF[i][j] != -1)
            {
                from = min(from, 1ll * distF[i][j] * w + a[i][j]);
            }
        }
    }
    ans = min(ans, to + from);
    if (ans == 1e18) cout << -1 << "\n";
    else cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}