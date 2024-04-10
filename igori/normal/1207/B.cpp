#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>

#define int long long
//#define double long double

using namespace std;

const long long MOD = 998244353;

long long a[50][50];
long long b[50][50];
long long n, m;

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    vector<pair<int, int> > ans;
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
            {
                b[i][j] = 1;
                b[i + 1][j] = 1;
                b[i][j + 1] = 1;
                b[i + 1][j + 1] = 1;
                ans.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
}