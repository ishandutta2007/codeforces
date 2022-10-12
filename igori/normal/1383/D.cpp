#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> x, y;
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, a[i][j]);
        }
        x.push_back(mx);
    }
    for (int j = 0; j < m; j++)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            mx = max(mx, a[i][j]);
        }
        y.push_back(mx);
    }
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    sort(y.begin(), y.end());
    reverse(y.begin(), y.end());
    vector<vector<int> > b(n, vector<int>(m));
    int r = 0, c = 0;
    queue<pair<int, int> > q;
    //cout << "\n";
    //for (auto e : x) cout << e << " ";
    //cout << "\n";
    //for (auto e : y) cout << e << " ";
    //cout << "\n";
    for (int i = n * m; i > 0; i--)
    {
        if (r < n && c < m && x[r] == i && y[c] == i)
        {
            b[r][c] = i;
            //cout << i << " " << r << " " << c << endl;
            for (int j = r - 1; j >= 0; j--)
            {
                q.push({j, c});
            }
            for (int j = c - 1; j >= 0; j--)
            {
                q.push({r, j});
            }
            r++;
            c++;
            continue;
        }
        if (r < n && x[r] == i)
        {
            b[r][c - 1] = i;
            for (int j = c - 2; j >= 0; j--)
            {
                q.push({r, j});
            }
            r++;
            continue;
        }
        if (c < m && y[c] == i)
        {
            b[r - 1][c] = i;
            for (int j = r - 2; j >= 0; j--)
            {
                q.push({j, c});
            }
            c++;
            continue;
        }
        if (!q.size())
        {
            continue;
            cout << -1;
            return 0;
        }
        pair<int, int> xy = q.front();
        q.pop();
        //cout << i << " -> " << xy.first << " " << xy.second << endl;
        b[xy.first][xy.second] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}