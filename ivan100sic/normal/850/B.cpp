#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, x, y;
int a[500005];
int c[2100005];

long long suma[2100005];
long long kaskada[2100005];

inline long long get_suma(int l, int r) {
	return suma[r] - suma[l-1];
}

inline long long get_kaskada(int l, int r) {
	return kaskada[r] - kaskada[l-1] - suma[l-1] * (r-l+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	for (int i=1; i<=2'000'005; i++) {
		suma[i] = suma[i-1] + c[i];
		kaskada[i] = kaskada[i-1] + suma[i-1];
	}

	long long sol = 6e18;

	for (int d=2; d<=1'000'000; d++) {

		long long tot = 0;

		int nazad = x / y;
		// bulk procesiraj range
		for (int l=1; l <= 1'000'000; l += d) {
			int r = l + d - 1;

			if (r-nazad > l) {
				tot += get_suma(l, r-nazad-1) * x + get_kaskada(r-nazad,r) * y;
			} else {
				tot += get_kaskada(l, r) * y;
			}
		}

		sol = min(sol, tot);
	}

	cout << sol;

}