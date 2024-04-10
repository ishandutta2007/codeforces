#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <cassert>
#include <map>
#include <set>
#include <ctime>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(X) ((int)((X).size()))

const double eps = 1e-8;
const int inf = 100000000;

const int N = 100005;

int n, m;
char a[4][N];
int f[4][N];

bool ok(int i, int j)
{
    return a[i][j] == '.' && a[i][j + 1] == '.' && a[i][j + 2] == '.';
}

int dp(int i, int j)
{
    if (i < 1 || i > 3) return false;
    if (j > n) return true;
    if (f[i][j] != -1) return f[i][j];
    int &ret = f[i][j];
    ret = 0;
    if (ok(i, j + 1) && dp(i, j + 3)) return ret = 1;
    if (a[i][j + 1] == '.')
    {
        if (ok(i - 1, j + 1) && dp(i - 1, j + 3)) return ret = 1;
        if (ok(i + 1, j + 1) && dp(i + 1, j + 3)) return ret = 1;
    }
    return ret;
}

int main()
{
    #ifdef LOCAL_TEST
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= n + 5; ++j)
                a[i][j] = '.';
        for (int i = 1; i <= 3; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        memset(f, -1, sizeof f);
        for (int i = 1; i <= 3; ++i)
            if (a[i][1] == 's')
            {
                if (dp(i, 1) == 1)
                    cout << "YES" << endl;
                else
                    cout << "NO" << endl;
                break;
            }
    }
    return 0;
}