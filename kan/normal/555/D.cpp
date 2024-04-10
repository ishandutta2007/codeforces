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

const int maxn = 200005;
const ll inf = 1e18;

ll x[maxn];
pair<int, int> p[maxn];
int wh[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i + 1].first);
        p[i + 1].second = i;
    }
    sort(p + 1, p + n + 1);
    for (int i = 0; i <= n + 1; i++) x[i] = p[i].first;
    x[0] = -inf;
    x[n + 1] = inf;
    for (int i = 1; i <= n; i++) wh[p[i].second] = i;
    int k = n + 2;
    for (int i = 0; i < m; i++)
    {
        int cur, l;
        scanf("%d%d", &cur, &l);
        cur--;
        cur = wh[cur];
        while (l >= x[cur + 1] - x[cur] || l >= x[cur] - x[cur - 1])
        {
//             cout << "cur " << cur << ' ' << x[cur] << ' ' << l << endl;
//             cout << x[3] << ' ' << upper_bound(x, x + k, x[cur] + l) - x << endl;
            int next = upper_bound(x, x + k, x[cur] + l) - x - 1;
//             cout << next << endl;
            l -= x[next] - x[cur];
//             cout << "next " << next << ' ' << x[next] << ' ' << l << endl;
            int next2 = lower_bound(x, x + k, x[next] - l) - x;
            l -= x[next] - x[next2];
            if (next2 == cur)
            {
                l %= 2 * (x[next] - x[cur]);
            }
            cur = next2;
        }
//         cout << cur << endl;
        printf("%d\n", p[cur].second + 1);
    }
	return 0;
}