#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>

#define pb push_back
#define mp make_pair

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

int main()
{

    int n, m;
    cin >> n >> m;
    char c;
    cin >> c;

    char a[120][120];
    int ans = 0;
    vector <int> used(30);
    used[c - 'A'] = 1;

    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        if (!(i >= 1 && i <= n && j >= 1 && j <= m)) a[i][j] = '.';
        else cin >> a[i][j];

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        if (a[i][j] == c)
    {
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (a[x][y] >= 'A' && a[x][y] <= 'Z' && !used[a[x][y] - 'A'])
            {
                used[a[x][y] - 'A'] = 1;
                ++ans;
            }
        }
    }

    cout << ans;

    cout << "\n";
    return 0;

}