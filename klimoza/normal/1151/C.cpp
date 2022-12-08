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

ll ans(ll n) {
	//cout << n << endl;
	if (n == 0) return 0;
	ll cnt1 = 0;
	ll cnt2 = 0;
	int type = 0;
	ll l;
	ll h;
	ll f = 0;
	for (int i = 0; i < 65; i++) {
		if (cnt1 + cnt2 + (1LL << i) >= n) {
			l = n - cnt1 - cnt2;
			//cout << "flex " << l << endl;
		}
		else {
			l = (1LL << i);
		}
		if (!type) {
			h = 2 * cnt1 + 1;
			cnt1 += (1LL << i);
		}
		else {
			h = 2 * cnt2 + 2;
			cnt2 += (1LL << i);
		}
		l %= mod;
		h %= mod;
		f += (l * (h + l - 1)) % mod;
		f %= mod;
		//cout << cnt1 << " " << cnt2 << " " << i << " " << l << " " << h << " " << f << endl;
		type ^= 1;
		if (cnt1 + cnt2 >= n) break;
	}
	//cout << f << endl;
	return f;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll l, r;
	cin >> l >> r;
	cout << (ans(r) - ans(l - 1) + mod) % mod << endl;
	//system("pause");
	return 0;
}