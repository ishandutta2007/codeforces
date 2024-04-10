#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <time.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

ll n;
ll a[600][600];
ll b[600][600];
ll m;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (a[i][j])
            {
                a[i][j] = 0;
                a[n - 1][j] ^= 1;
                a[i][m - 1] ^= 1;
                a[n - 1][m - 1] ^= 1;
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (b[i][j])
            {
                b[i][j] = 0;
                b[n - 1][j] ^= 1;
                b[i][m - 1] ^= 1;
                b[n - 1][m - 1] ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes";
}