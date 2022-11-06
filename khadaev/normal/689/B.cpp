#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	forn(i, 0, n) {
		scanf("%d", &a[i]);
		--a[i];
	}
	vector<int> used(n);
	vector<int> ans(n);
	vector<int> list = {0};
	int cnt = 0;
	while (!list.empty()) {
		vector<int> next;
		for (int j : list) {
			if (used[j]) continue;
			used[j] = 1;
			ans[j] = cnt;
			next.eb(a[j]);
			if (j) next.eb(j - 1);
			if (j < n - 1) next.eb(j + 1);
		}
		++cnt;
		list = next;
	}
	forn(i, 0, n) printf("%d ", ans[i]);
	return 0;
}