#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")	
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> p(n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i] * (n - a[i] + 1);
	}
	ll f1 = 0, f2 = 0;
	for (int i = 1; i < n; i++) {
		f1 = min(a[i], a[i - 1]);
		f2 = max(a[i], a[i - 1]);
		ans -= f1 * (n - f2 + 1);
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}