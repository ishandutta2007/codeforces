#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int N = 3e5 + 10;
int n;
struct Point {
    int x, y;
    void read() {
        scanf("%d%d", &x, &y);
    }
} pts[N];

int calc(vector<int> ids) {
    int minx = 1e9;
    int maxx = -1e9;
    int miny = 1e9;
    int maxy = -1e9;
    for(auto t : ids) {
        minx = min(minx, pts[t].x);
        maxx = max(maxx, pts[t].x);
        miny = min(miny, pts[t].y);
        maxy = max(maxy, pts[t].y);
    }
    return 2 * (maxy - miny + maxx - minx);
}

void solve()
{
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        pts[i].read();
    int minxId = 0;
    int maxxId = 0;
    int minyId = 0;
    int maxyId = 0;
    for(int i = 0; i < n; ++i) {
        if (pts[i].x < pts[minxId].x)
            minxId = i;
        if (pts[i].x > pts[maxxId].x)
            maxxId = i;
        if (pts[i].y < pts[minyId].y)
            minyId = i;
        if (pts[i].y > pts[maxyId].y)
            maxyId = i;
    }
    int ans1 = -1;
    for(int i = 0; i < n; ++i) {
        ans1 = max(ans1, calc({i, minyId, maxyId}));
        ans1 = max(ans1, calc({maxxId, i, maxyId}));
        ans1 = max(ans1, calc({maxxId, minyId, i}));
        ans1 = max(ans1, calc({minxId, i, maxyId}));
        ans1 = max(ans1, calc({minxId, minyId, i}));
        ans1 = max(ans1, calc({minxId, maxxId, i}));
    }
    printf("%d ", ans1);
    int ans2 = calc({minxId, maxxId, minyId, maxyId});
    for(int i = 4; i <= n; ++i)
        printf("%d ", ans2);
    puts("");
}

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		ios_base::sync_with_stdio(false);
		while (true)
			solve();
#endif

#ifdef CASES
#define MULTITEST
#endif

#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
	dbg_time();
}