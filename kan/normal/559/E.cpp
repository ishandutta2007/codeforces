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

const int maxn = 105;

#define left left_fdg
#define right right_fdg

const int inf = 1e9;

struct pt
{
    int x, l;
};

inline bool operator<(const pt &a, const pt &b)
{
    return a.x < b.x;
}

pt p[maxn];
int n;
vector<int> xs;
int ans[3 * maxn][maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].l);
        xs.pb(p[i].x);
        xs.pb(p[i].x - p[i].l);
        xs.pb(p[i].x + p[i].l);
    }
    xs.pb(-inf);
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());
    sort(p, p + n);
    for (int i = 0; i < (int)xs.size(); i++)
    {
        for (int j = 0; j < n; j++) if (p[j].x >= xs[i])
        {
//             cout << i << ' ' << j << ' ' << xs[i] << ' ' << p[j].x << ' ' << ans[i][j] << endl;
            for (int t = j; t < n; t++) if (p[t].x - p[t].l <= p[j].x)
            {
                int left = p[t].x - p[t].l;
                int right = p[t].x;
                int k = j;
                while (k < n && p[k].x <= right)
                {
                    if (k != t) right = max(right, p[k].x + p[k].l);
                    k++;
                }
                int wh = lower_bound(all(xs), right) - xs.begin();
                ans[wh][k] = max(ans[wh][k], ans[i][j] + right - max(left, xs[i]));
//                 cout << "with " << t << ' ' << left << ' ' << right << ' ' << wh << ' ' << k << ' ' << ans[i][j] + right - max(left, xs[i]) << endl;
            }
            //all right
            int left = p[j].x;
            int right = p[j].x;
            int k = j;
            while (k < n && p[k].x <= right)
            {
                right = max(right, p[k].x + p[k].l);
                k++;
            }
            int wh = lower_bound(all(xs), right) - xs.begin();
            ans[wh][k] = max(ans[wh][k], ans[i][j] + right - max(left, xs[i]));
//             cout << "right " << left << ' ' << right << ' ' << wh << ' ' << k << ' ' << ans[i][j] + right - max(left, xs[i]) << endl;
        }
    }
    int answer = 0;
    for (int i = 0; i < (int)xs.size(); i++) answer = max(answer, ans[i][n]);
    cout << answer << endl;
	return 0;
}