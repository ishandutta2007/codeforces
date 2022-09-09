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

const int maxn = 25;
const int maxmask = (1 << 21) + 5;
const int inf = 1e9;

int ans[maxmask];
char p[maxn][maxn];
int curmask[30];
int sumcost[30];
int maxcost[30];
int a[maxn][maxn];
int n, m;

void upd(int &a, int b)
{
    a = min(a, b);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", p[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    }
    int km = 1 << n;
    for (int mask = 0; mask < km; mask++) ans[mask] = inf;
    ans[0] = 0;
    for (int i = 0; i < m; i++)
    {
//         cout << "new i = " << i << endl;
        for (int c = 0; c < 26; c++)
        {
            curmask[c] = 0;
            sumcost[c] = 0;
            maxcost[c] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            curmask[p[j][i] - 'a'] |= (1 << j);
            sumcost[p[j][i] - 'a'] += a[j][i];
            maxcost[p[j][i] - 'a'] = max(maxcost[p[j][i] - 'a'], a[j][i]);
        }
        for (int mask = 0; mask < km; mask++)
        {
//             cout << mask << ' ' << ans[mask] << endl;
            for (int c = 0; c < 26; c++) if (curmask[c] != 0)
            {
                upd(ans[mask | curmask[c]], ans[mask] + sumcost[c] - maxcost[c]);
            }
            for (int j = 0; j < n; j++)
            {
                upd(ans[mask | (1 << j)], ans[mask] + a[j][i]);
            }
        }
    }
    cout << ans[km - 1] << endl;
	return 0;
}