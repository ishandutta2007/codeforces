#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int r, c, n, k, a[11][11];

int main()
{
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);/**/
    cin >> r >> c >> n >> k;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            a[i][j] = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        a[x][y] = 1;
    }
    int ans = 0;
    for (int l1 = 0; l1 < r; l1++)
        for (int r1 = l1; r1 < r; r1++)
            for (int l2 = 0; l2 < c; l2++)
                for (int r2 = l2; r2 < c; r2++)
                {
                    int kol = 0;
                    for (int i = l1; i <= r1; i++)
                        for (int j = l2; j <= r2; j++)
                            kol += a[i][j];
                    ans += (kol >= k);
                }
    cout << ans;
    return 0;
}