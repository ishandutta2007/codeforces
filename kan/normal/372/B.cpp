#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 42;

int ans[maxn][maxn][maxn][maxn];
int kvleft[maxn][maxn];
int n, m, k;
char p[maxn][maxn];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++) scanf("%s", p[i]);
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++) kvleft[i][j + 1] = (p[i][j] == '0' ? kvleft[i][j] + 1 : 0);
    }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 1; j <= m; j++) cout << kvleft[i][j] << ' ';
//         cout << endl;
//     }
    for (int sx = 0; sx < n; sx++)
    {
        for (int sy = 0; sy < m; sy++)
        {
            for (int i = sx; i < n; i++)
            {
                for (int j = sy; j < m; j++)
                {
                    ans[sx][sy][i + 1][j + 1] = ans[sx][sy][i][j + 1] + ans[sx][sy][i + 1][j] - ans[sx][sy][i][j];
//                     cout << sx << ' ' << sy << ' ' << i << ' ' << j << ' ' << ans[sx][sy][i + 1][j + 1] << endl;
                    int maxlen = (j - sy + 1);
                    for (int t = i; t >= sx; t--)
                    {
                        maxlen = min(maxlen, kvleft[t][j + 1]);
//                         cout << maxlen << ' ' << kvleft[t][j + 1] << endl;
                        ans[sx][sy][i + 1][j + 1] += maxlen;
                    }
//                     cout << sx << ' ' << sy << ' ' << i << ' ' << j << ' ' << ans[sx][sy][i + 1][j + 1] << endl;
                }
            }
        }
    }
    
    for (int T = 0; T < k; T++)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        printf("%d\n", ans[a - 1][b - 1][c][d]);
    }
	return 0;
}