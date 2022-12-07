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

const int N = 25;
int prec[N];

void solve() {
    int q;
    cin >> q;
    for(int i = 1; i <= N; ++i) {
        auto x = (1 << i) - 1;
        dbg(i, x);
        prec[i - 1] = 1;
        for(int d = 2; d * d <= x; ++d)
            if (x % d == 0) {
                prec[i - 1] = x / d;
                break;
            }
    }
    dbg(ARR(prec, N));
    for(int i = 0; i < q; ++i) {
        int a;
        cin >> a;
        int ia = a;
        for(int j = 0; (1 << j) <= a; ++j)
            a |= (1 << j);
        if (a != ia) {
            cout << a << endl;
            continue;
        }
        ++a;
        int id = 0;
        for(; a > 1; a >>= 1)
            ++id;
        dbg(id);
        cout << prec[id - 1] << endl;
    }
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