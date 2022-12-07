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

ll distribute_ints(vector<int> ints, vector<int> friends) {
    sort(ints.begin(), ints.end());
    ll total = 0;
    sort(friends.begin(), friends.end());
    for(auto f : friends) {
        if (f == 1) {
            total += 2 * ints.back();
        } else {
            total += ints.back();
        }
        ints.pop_back();
    }
    reverse(friends.begin(), friends.end());
    reverse(ints.begin(), ints.end());
    for(auto f : friends) {
        if (f == 1)
            break;
        total += ints.back();
        for(int i = 0; i < f - 1; ++i)
            ints.pop_back();
    }
    // assert(ints.size() == 0);
    return total;
}

void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> ints(n);
    vector<int> friends(k);
    for(auto& i : ints)
        scanf("%d", &i);
    for(auto& f : friends)
        scanf("%d", &f);
    printf("%lld\n", distribute_ints(ints, friends));
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