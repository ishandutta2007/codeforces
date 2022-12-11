#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int cnt(int a, int b, int x) {
	int rg = b / x;
	int lf = (a + x - 1) / x;
	if (lf <= rg) {
		return rg - lf + 1;
	} else {
		return 0;
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	int n;
	int x, k;
	cin >> n >> x >> k;

	map<int, int> mapa;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++mapa[a[i]];
	}
	sort(all(a));

	ll ans = 0;

	for (int i = 0; i < n - 1; ++i) {
		int lf = i + 1, rg = n;
		while (rg - lf > 1) {
			int md = (lf + rg) >> 1;
			int c = cnt(a[i], a[md], x);
			if (c <= k) {
				lf = md;
			} else {
				rg = md;
			}
		}
		if (cnt(a[i], a[lf], x) != k) {
			continue;
		}
		int hi = lf;
		lf = i, rg = n - 1;
		while (rg - lf > 1) {
			int md = (lf + rg) >> 1;
			if (cnt(a[i], a[md], x) >= k) {
				rg = md;
			} else {
				lf = md;
			}
		}
		assert(cnt(a[i], a[rg], x) == k);
		int lo = rg;
		assert(lo <= hi);
		ans += hi - lo + 1;
	}

	for (auto it : mapa) {
		if ((k == 0 && it.first % x) || (k == 1 && it.first % x == 0)) {
			ans += ll(it.second) * (it.second + 1) / 2;
		}
	}

	cout << ans << "\n";

}