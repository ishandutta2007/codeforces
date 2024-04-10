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

const int N = 1e5 + 10;
int n, m;
int xs[N];
int hxs[N];

void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &xs[i]);
        --xs[i];
    }
    int nm = 0;
    int add = 0;
    for(int i = 0; i < m; ++i) {
        int x1, x2, y;
        scanf("%d%d%d", &x1, &x2, &y);
        if (x1 != 1) {
            continue;
        }
        if (x2 == 1e9) {
            ++add;
            continue;
        }
        hxs[nm++] = x2 - 1;
    }
    m = nm;
    int ans = n + m;
    sort(xs, xs + n);
    sort(hxs, hxs + m);
    xs[n++] = 1e9 + 10;
    int ptr = 0;
    dbg(ARR(xs, n), ARR(hxs, m));
    for(int i = 0; i < n; ++i) {
        while(ptr < m && hxs[ptr] < xs[i])
            ++ptr;
        ans = min(ans, i + m - ptr);
    }
    printf("%d\n", ans + add);
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