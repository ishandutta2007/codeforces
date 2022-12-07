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


const int N = 1e6 + 10;
const int L = 7;
int n, m;
int cnt[N];
int dp[N][L][L];

void relax(int& a, int b) {
    a = max(a, b);
}

void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        --x;
        ++cnt[x];
    }
    int ans = 0;
    //dbg(ARR(cnt, m + 1));
    for(int i = 0; i + 1 < N; ++i) {
        for(int c1 = 0; c1 < L; ++c1) {
            for(int c2 = 0; c2 < L; ++c2) {
                if (cnt[i] < c1 || cnt[i + 1] < c2)
                    continue;
                auto cur = dp[i][c1][c2];
                relax(ans, cur);
                auto can = min({cnt[i] - c1, cnt[i + 1] - c2, cnt[i + 2], 2});
                for(int j = 0; j <= can; ++j) {
                    relax(dp[i + 1][c2 + j][j], cur + j + (cnt[i] - c1 - j) / 3);
                }
            }
        }
    }
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