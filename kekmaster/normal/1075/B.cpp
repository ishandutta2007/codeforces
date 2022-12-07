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

const int N = 2e5 + 10;
int n, m;
int a[N];
int t[N];
int ans[N];

void solve()
{
    scanf("%d%d", &n, &m);
    n += m;
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    vector<int> tax;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
        if (t[i])
            tax.push_back(a[i]);
    }
    auto curt = 0;
    for(int i = 0; i < n; ++i) {
        dbg(i, curt);
        if (curt + 1 < m && tax[curt + 1] <= a[i])
            ++curt;
        if (t[i])
            continue;
        auto prv = tax[curt];
        int nxt = 2e9 + 10;
        if (curt + 1 < m)
            nxt = tax[curt + 1];
        if (abs(a[i] - prv) <= abs(a[i] - nxt)) {
            ++ans[curt];
        } else {
            ++ans[curt + 1];
        }
    }
    for(int i = 0; i < m; ++i)
        printf("%d ", ans[i]);
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