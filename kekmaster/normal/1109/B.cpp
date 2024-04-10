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

void solve() {
    string s;
    cin >> s;
    for(int i = 0; i + 1 < (int)s.size(); ++i) {
        auto t = s.substr(i + 1) + s.substr(0, i + 1);
        if (t == s)
            continue;
        bool ok = true;
        for(int j = 0; j < (int)t.size(); ++j)
            ok &= t[j] == t[t.size() - 1 - j];
        if (ok) {
            cout << 1 << endl;
            return;
        }
    }
    int id = 1;
    while(id < (int)s.size() && s[id] == s[id - 1])
        ++id;
    if (id == (int)s.size() || 2 * id + 1 == (int)s.size()) {
        cout << "Impossible" << endl;
    } else {
        cout << 2 << endl;
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