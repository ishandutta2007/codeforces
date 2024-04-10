#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

int n, m, q;
string s[500];
int a[500][500];
int pref[4][500][500];
int w[251][500][500];

int get_pref(int c, int x, int y)
{
    if (x < 0 || y < 0) return 0;
    return pref[c][x][y];
}

int get_pref_window(int c, int x1, int y1, int x2, int y2)
{
    if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= n || x2 >= n || y1 >= m || y2 >= m) return 0;
    return get_pref(c, x2, y2) - get_pref(c, x1 - 1, y2) - get_pref(c, x2, y1 - 1) + get_pref(c, x1 - 1, y1 - 1);
}

int get_w(int k, int i, int j)
{
    if (i < 0 || j < 0) return 0;
    return w[k][i][j];
}

int get_w_window(int c, int x1, int y1, int x2, int y2)
{
    if (y1 > y2 || x1 > x2 || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 >= n || x2 >= n || y1 >= m || y2 >= m) return 0;
    return get_w(c, x2, y2) - get_w(c, x1 - 1, y2) - get_w(c, x2, y1 - 1) + get_w(c, x1 - 1, y1 - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = (s[i][j] == 'G') * 1 + (s[i][j] == 'Y') * 2 + (s[i][j] == 'B') * 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 4; k++)
                pref[k][i][j] = get_pref(k, i - 1, j) + get_pref(k, i, j - 1) - get_pref(k, i - 1, j - 1) + (a[i][j] == k);
    for (int i = 1; i < n; i++)
    for (int j = 1; j < m; j++)
    {
        if (a[i][j] == 3 && a[i - 1][j - 1] == 0 && a[i - 1][j] == 1 && a[i][j - 1] == 2)
        {
            for (int sz = 1; ; sz++)
            {
                if (get_pref_window(3, i, j, i + sz - 1, j + sz - 1) == sz * sz && get_pref_window(0, i - sz, j - sz, i - 1, j - 1) == sz * sz &&
                    get_pref_window(1, i - sz, j, i - 1, j + sz - 1) == sz * sz && get_pref_window(2, i, j - sz, i + sz - 1, j - 1) == sz * sz)
                    w[sz][i][j]++;
                else break;
            }
        }
    }
    for (int sz = 1; sz <= 250; sz++)
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) w[sz][i][j] += get_w(sz, i - 1, j) + get_w(sz, i, j - 1) - get_w(sz, i - 1, j - 1);
    while (q--)
    {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2, y2--, x2--;
        int ans = 0;
        for (int i = 1; i; i++)
        {
            if (get_w_window(i, x1, y1, x2, y2) > 0) ans = i, x1++, y1++, x2--, y2--;
            else break;
        }
        cout << 4 * ans * ans << "\n";
    }
}