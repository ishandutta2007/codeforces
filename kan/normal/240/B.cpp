#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn = 205;
const int maxa = 40005;
const int inf = 1000000000;

int ans[maxn][maxa][2];
int h[maxn], sum[maxn];
int n, a, b;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    sum[0] = 0;
    for (int i = 0; i < n; i++) sum[i + 1] = sum[i] + h[i + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            ans[i][j][0] = inf;
            ans[i][j][1] = inf;
        }
    }
    ans[0][0][0] = 0;
    ans[0][0][1] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= a; j++)
        {
//             cerr << i << ' ' << j << ' ' << ans[i][j][0] << ' ' << ans[i][j][1] << endl;
            if (j + h[i + 1] <= a)
            {
                ans[i + 1][j + h[i + 1]][0] = min(ans[i + 1][j + h[i + 1]][0], min(ans[i][j][0], ans[i][j][1] + min(h[i], h[i + 1])));
            }
//             cerr << sum[i] - j << endl;
            if (sum[i] - j + h[i + 1] <= b)
            {
                ans[i + 1][j][1] = min(ans[i + 1][j][1], min(ans[i][j][1], ans[i][j][0] + min(h[i], h[i + 1])));
            }
        }
    }
    int mina = inf;
    for (int i = 0; i <= a; i++) mina = min(mina, min(ans[n][i][0], ans[n][i][1]));
    cout << (mina == inf ? -1 : mina) << endl;
    return 0;
}