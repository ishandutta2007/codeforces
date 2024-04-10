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

const int P = 1e9 + 7;
int sum(int a, int b) {
    a += b;
    return a >= P ? a - P : a;
}
int sub(int a, int b) {
    return sum(a, P - b);
}
int mul(int a, int b) {
    return (ll) a * b % P;
}
int bpow(int x, int pw) {
    int res = 1;
    for(; pw > 0; pw /= 2, x = mul(x, x))
        if (pw % 2 == 1)
            res = mul(res, x);
    return res;
}
int inv(int x) {
    return bpow(x, P - 2);
}

const int N = 1e6 + 10;
int fact[N], rfact[N];
int mpw[N], npw[N];
int cnk(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}

void solve() {
    int n,m;
    cin >> n >> m;
    npw[0] = mpw[0] = 1;
    for(int i = 1; i < N; ++i) {
        mpw[i] = mul(mpw[i - 1], m);
        npw[i] = mul(npw[i - 1], n);
    }
    fact[0] = 1;
    for(int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
    }
    rfact[N - 1] = inv(fact[N - 1]);
    for(int i = N - 2; i >= 0; --i)
        rfact[i] = mul(rfact[i + 1], i + 1);
    int ans = 0;
    for(int l = 1; l < n; ++l) {
        auto btw = mul(cnk(n - 2, l - 1), fact[l - 1]);
        auto ed = mul(mpw[n - 1 - l], cnk(m - 1, l - 1));
        auto out = 1;
        if (l != n - 1)
            out = mul(npw[n - l - 2], l + 1);
        ans = sum(ans, mul(btw, mul(ed, out)));
    }
    cout << ans << endl;
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