#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define int long long

int n;
int x[500], y[500];
int ax, ay, bx, by;
int xx, yy, t;

const int INF = 3e16;

int dist(int a, int b)
{
    return abs(x[a] - x[b]) + abs(y[a] - y[b]);
}

signed main()
{
    cin >> x[1] >> y[1] >> ax >> ay >> bx >> by;
    for (int i = 2; i <= 100; i++)
    {
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        if (x[i] > INF || y[i] > INF)
        {
            n = i;
            break;
        }
    }
    cin >> xx >> yy >> t;
    x[0] = xx, y[0] = yy;
    int ans = 0;
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            int minlen = 1e18;
            int cnt = r - l + 1;
            for (int i = l; i <= r; i++)
            {
                int len = 0;
                int p = 0;
                for (int j = i; j >= l; j--) len += dist(p, j), p = j;
                for (int j = i + 1; j <= r; j++) len += dist(p, j), p = j;
                minlen = min(minlen, len);
                len = 0, p = 0;
                for (int j = i; j <= r; j++) len += dist(p, j), p = j;
                for (int j = i - 1; j >= l; j--) len += dist(p, j), p = j;
            }
            if (minlen <= t) ans = max(ans, cnt);
        }
    }
    cout << ans;
}