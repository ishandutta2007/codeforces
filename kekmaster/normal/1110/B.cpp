#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
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
int n, m , k, b[N];

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    vector<int> dists;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        if (i > 0)
            dists.push_back(b[i] - b[i - 1]);
    }
    int ans = b[n - 1] - b[0] + 1;
    sort(dists.begin(), dists.end());
    reverse(dists.begin(), dists.end());
    for(int i = 0; i < k - 1; ++i)
        ans -= dists[i] - 1;
    printf("%d\n", ans);
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
}