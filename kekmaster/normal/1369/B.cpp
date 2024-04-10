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

string read_str() {
    static char buf[100500];
    scanf("%s", buf);
    return buf;
}

void solve() {
    int n;
    scanf("%d", &n);
    auto s = read_str();
    // 001
    // 0001010101111 -> 00001111 
    bool has10 = false;
    for(int i = 0; i + 1 < (int)s.size(); ++i)
        if (s[i] == '1' && s[i + 1] == '0')
            has10 = true;
    if (!has10) {
        printf("%s\n", s.c_str());
        return;
    }
    int zs = 0;
    int os = 0;
    while(s[zs] == '0')
        ++zs;
    while(s[s.size() - 1 - os] == '1')
        ++os;
    ++zs;
    string res;
    while(zs--)
        res.push_back('0');
    while(os--)
        res.push_back('1');
    printf("%s\n", res.c_str());
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