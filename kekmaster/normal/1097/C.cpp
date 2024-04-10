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
int n;
string s[N];
char buf[5 * N];
int minb[N];
int bal[N];

void proc(int id) {
    for(auto c : s[id]) {
        if (c == '(')
            ++bal[id];
        else
            --bal[id];
        minb[id] = min(minb[id], bal[id]);
    }
}

void solve()
{
    map<int, int> cnt1, cnt2;
    int cnt3 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%s", buf);
        s[i] = buf;
        proc(i);
        if (bal[i] == 0 && minb[i] == 0) {
            ++cnt3;
        } else if(bal[i] > 0 && minb[i] == 0) {
            ++cnt1[bal[i]];
        } else if(bal[i] < 0 && minb[i] == bal[i]) {
            ++cnt2[-bal[i]];
        }
    }
    int ans = cnt3 / 2;
    for(auto it : cnt1) {
        ans += min(it.second, cnt2[it.first]);
    }
    printf("%d\n", ans);
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