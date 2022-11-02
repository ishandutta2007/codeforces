#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
//#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

int n, m;

bool a[510][510];
bool b[510][510];

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int DX[] = {-1, 0, 0, 1};
const int DY[] = {0, -1, 1, 0};

bool good(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool get(int x, int y)
{
    if (!good(x, y)) return false;
    return a[x][y];
}

bool check(int x, int y, int dir1 = -1, int dir2 = -1)
{
    for (int dir = 0; dir < 8; dir++)
    {
        if (dir == dir1 || dir == dir2) continue;
        if (good(x + dx[dir], y + dy[dir]) && a[x + dx[dir]][y + dy[dir]]) return false;
    }
    return true;
}

bool checkd(int x, int y, int dir1 = -1, int dir2 = -1)
{
    for (int dir = 0; dir < 4; dir++)
    {
        if (dir1 != -1 && DX[dir] == dx[dir1] && DY[dir] == dy[dir1]) continue;
        if (dir2 != -1 && DX[dir] == dx[dir2] && DY[dir] == dy[dir2]) continue;
        if (good(x + DX[dir], y + DY[dir]) && a[x + DX[dir]][y + DY[dir]]) return false;
    }
    return true;
}

int main()
{
    int tc;
    cin >> tc;
    for (int it = 0; it < tc; it++)
    {
        cin >> n >> m;
        vector<string> v(n);
        memset(a, 0, sizeof(a));
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int64 res = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = v[i][j] == '1';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (!a[i][j]) continue;
                for (int k = 2; j + k - 1 < m && i + k - 1 < n; k++)
                {
                    if (!a[i + k - 1][j] || !a[i][j + k - 1]) break;
                    if (get(i + k, j) || get(i, j + k)) continue;
                    bool ok = true;
                    for (int t = 0; t < k; t++)
                        if (!a[i + k - 1][j + t] || !a[i + t][j + k - 1])
                        {
                            ok = false;
                            break;
                        }
                    if (!ok) continue;
                    for (int t = 0; t < k; t++)
                    {
                        a[i + k - 1][j + t] = a[i][j + t] = a[i + t][j + k - 1] = a[i + t][j] = 0;
                    }
                    for (int t = 0; t < k && ok; t++)
                    {
                        if (!check(i + k - 1, j + t)) ok = false;
                        if (!check(i, j + t)) ok = false;
                        if (!check(i + t, j + k - 1)) ok = false;
                        if (!check(i + t, j)) ok = false;
                    }
                    for (int t = 0; t < k; t++)
                    {
                        a[i + k - 1][j + t] = a[i][j + t] = a[i + t][j + k - 1] = a[i + t][j] = 1;
                    }
                    if (ok) res++;
                }
                for (int k = 2; i + 2 * k - 2 < n && j + k - 1 < m && j - k + 1 >= 0; k++)
                {
                    if (!a[i + k - 1][j - k + 1] || !a[i + k - 1][j + k - 1]) break;
                    if (get(i + k, j - k) || get(i + k, j + k)) continue;
                    bool ok = true;
                    for (int t = 0; t < k; t++)
                        if (!a[i + k - 1 + t][j - k + 1 + t] || !a[i + k - 1 + t][j + k - 1 - t])
                        {
                            ok = false;
                            break;
                        }
                    if (!ok) continue;
                    for (int t = 0; t < k; t++)
                    {
                        a[i + k - 1 + t][j - k + 1 + t] = a[i + t][j - t] = a[i + t][j + t] = a[i + k - 1 + t][j + k - 1 - t] = 0;
                    }
                    for (int t = 0; t < k && ok; t++)
                    {
                        if (!check(i + k - 1 + t, j - k + 1 + t)) ok = false;
                        if (!check(i + t, j - t)) ok = false;
                        if (!check(i + t, j + t)) ok = false;
                        if (!check(i + k - 1 + t, j + k - 1 - t)) ok = false;
                    }
                    for (int t = 0; t < k; t++)
                    {
                        a[i + k - 1 + t][j - k + 1 + t] = a[i + t][j - t] = a[i + t][j + t] = a[i + k - 1 + t][j + k - 1 - t] = 1;
                    }
                    if (ok) res++;
                }
            }
        cout << res << "\n";
    }
    return 0;
}