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

#define pb push_back
#define all(x) begin(x), end(x)

const int maxn = 505;

int ans[2][maxn][maxn * 2];
int n, m, B, mod;
int a[maxn];

inline void upd(int &a, int b)
{
    a = (a + b) % mod;
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &B, &mod);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    ans[0][0][0] = 1 % mod;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int e = 0; e <= B; e++)
            {
                ans[(i + 1) & 1][j][e] = 0;
            }
        }
        for (int j = 0; j <= m; j++)
        {
            for (int e = 0; e <= B; e++)
            {
                upd(ans[i & 1][j + 1][e + a[i]], ans[i & 1][j][e]);
                upd(ans[(i + 1) & 1][j][e], ans[i & 1][j][e]);
            }
        }
    }
    int answer = 0;
    for (int e = 0; e <= B; e++) upd(answer, ans[n & 1][m][e]);
    cout << answer << endl;
	return 0;
}