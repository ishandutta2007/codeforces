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

const int maxn = 5005;
const int inf = 1e9;

int ans[maxn][maxn];
int rright[maxn][maxn];
int a[maxn];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = inf;
    for (int i = 1; i < n; i++)
    {
        ll sum = a[i];
        ll suml = 0;
        int cur = i;
        for (int j = i - 1; j >= 0; j--)
        {
            suml += a[j];
            while (sum < suml)
            {
                cur++;
                sum += a[cur];
            }
            rright[i][j] = cur;
//             cout << i << ' ' << j << ' ' << rright[i][j] << endl;
        }
    }
    ans[n - 1][n] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            ans[i][j] = ans[i][j + 1] + 1;
            if (rright[j][i] < n) ans[i][j] = min(ans[i][j], ans[j][rright[j][i] + 1] + rright[j][i] - j);
        }
    }
    cout << ans[0][1] << endl;
	return 0;
}