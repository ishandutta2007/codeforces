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

const int maxn = 105;

int a[maxn][maxn];
int sumrow[maxn], sumcol[maxn], wasrow[maxn], wascol[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    }
    memset(sumrow, 0, sizeof sumrow);
    memset(sumcol, 0, sizeof sumcol);
    memset(wasrow, 0, sizeof wasrow);
    memset(wascol, 0, sizeof wascol);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) sumrow[i] += a[i][j], sumcol[j] += a[i][j];
    }
    bool found = true;
    while (found)
    {
        found = false;
        for (int i = 0; i < n; i++) if (sumrow[i] < 0)
        {
            found = true;
            wasrow[i] ^= 1;
            sumrow[i] *= -1;
            for (int j = 0; j < m; j++)
            {
                a[i][j] *= -1;
                sumcol[j] += 2 * a[i][j];
            }
        }
        for (int j = 0; j < m; j++) if (sumcol[j] < 0)
        {
            found = true;
            wascol[j] ^= 1;
            sumcol[j] *= -1;
            for (int i = 0; i < n; i++)
            {
                a[i][j] *= -1;
                sumrow[i] += 2 * a[i][j];
            }
        }
    }
    int krow = 0;
    for (int i = 0; i < n; i++) krow += wasrow[i];
    printf("%d", krow);
    for (int i = 0; i < n; i++) if (wasrow[i]) printf(" %d", i + 1);
    printf("\n");
    int kcol = 0;
    for (int i = 0; i < m; i++) kcol += wascol[i];
    printf("%d", kcol);
    for (int i = 0; i < m; i++) if (wascol[i]) printf(" %d", i + 1);
    return 0;
}