#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<functional>
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

#define MULTITEST
const int N = 2e6 + 10;
const int P = 1e9 + 7;
int sum(int a, int b) {
    a += b;
    if (a < P)
        return a;
    return a - P;
}

int dp[N];
bool used[N];

void precalc() {
    static bool done = false;
    if (done)
        return;
    done = true;
    dp[3] = 4;
    used[3] = true;
    for(int i = 4; i < N; ++i) {
        dp[i] = sum(dp[i - 1], sum(dp[i - 2], dp[i - 2]));
        // if (i % 3 == 0)
        if (!used[i - 1] && !used[i - 2]) {
            used[i] = true;
            dp[i] = sum(dp[i], 4);
        }
    }
}

void solve() {
    precalc();
    int n;
    scanf("%d", &n);
    printf("%d\n", dp[n]);
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