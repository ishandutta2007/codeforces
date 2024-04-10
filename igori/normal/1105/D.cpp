#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
long long n, m, p;
string c[1500];
long long a[1500];
int nx[4] = {0, -1, 0, 1};
int ny[4] = {1, 0, -1, 0};

bool ok(int a, int b)
{
    if (0 <= a && a < n && 0 <= b && b < m)
    return 1;
    return 0;
}

signed main()
{
    vector<pair<int, int> > fill;
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    for (char cc = '1'; cc < '1' + p; cc++)
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c[i][j] == cc)
            {
                fill.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < fill.size(); i++)
    {
        int cx = fill[i].first;
        int cy = fill[i].second;
        int cz = c[cx][cy] - '1';
        vector<pair<pair<int, int>, int> > bfs2;
        bfs2.push_back({{cx, cy}, 0});
        for (int j = 0; j < bfs2.size(); j++)
        {
            int d = bfs2[j].second;
            if (d == a[cz])
            {
                break;
            }
            else
            {
                int cxx = bfs2[j].first.first;
                int cyy = bfs2[j].first.second;
                for (int k = 0; k < 4; k++)
                {
                    if (ok(cxx + nx[k], cyy + ny[k]) && c[cxx + nx[k]][cyy + ny[k]] == '.')
                    {
                        c[cxx + nx[k]][cyy + ny[k]] = c[cx][cy];
                        bfs2.push_back({{cxx + nx[k], cyy + ny[k]}, d + 1});
                        fill.push_back({cxx + nx[k], cyy + ny[k]});
                    }
                }
                
            }
        }
    }
    for (char cc = '1'; cc < '1' + p; cc++)
    {
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (c[i][j] == cc)
                    r++;
            }
        }
        cout << r << " ";
    }
}