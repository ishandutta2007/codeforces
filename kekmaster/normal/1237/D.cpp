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

const int N = 3e5 + 10;
const int LOGN = 19;

#define log2 wqdiodhwqidowhq

int n, n2, n3;
int a[N];

int st[LOGN][N];
int p2[LOGN + 2];
int log2[N];
int dist[N];

void build_st() {
    for(int i = 0; i < LOGN + 2; ++i)
        p2[i] = 1 << i;
    for(int i = 2; i < N; ++i) {
        log2[i] = log2[i - 1];
        if (i == p2[log2[i] + 1])
            ++log2[i];
    }
    for(int i = 0; i < n3; ++i)
        st[0][i] = a[i];
    for(int i = 1; i < LOGN; ++i)
        for(int j = 0; j < n3; ++j)
            st[i][j] = min(st[i - 1][j], st[i - 1][min(n3 - 1, j + p2[i - 1])]);
}

int ask(int l, int r) {
    int pw = log2[r - l + 1];
    return min(st[pw][l], st[pw][r + 1 - p2[pw]]);
}

int ans[N];

void solve() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        a[i + 2 * n] = a[i];
    }
    n2 = 2 * n;
    n3 = 3 * n;
    build_st();
    int mn = *min_element(a, a + n);
    int mx = *max_element(a, a + n);
    for(int i = 0; i < n2; ++i) {
        if (a[i] <= mn * 2) {
            dist[i] = n3;
            continue;
        }
        int l = i;
        int r = n3;
        while(r - l > 1) {
            int m = (l + r) / 2;
            if (ask(i, m) * 2 < a[i])
                r = m;
            else
                l = m;
        }
        dist[i] = r;
    }
    dbg(ARR(dist, n2));
    if (mn * 2 >= mx) {
        for(int i = 0; i < n; ++i)
            printf("-1 ");
        puts("");
        return;
    }
    int clos = n3;
    for(int i = n2 - 1; i >= 0; --i) {
        clos = min(clos, dist[i]);
        ans[i] = clos - i;
    }
    for(int i = 0; i < n; ++i)
        printf("%d ", ans[i]);
    puts("");
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
    return 0;
}