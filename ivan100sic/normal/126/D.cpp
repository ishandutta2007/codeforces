#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<ll> fib = { 1, 2 };
	for (int i = 0; i < 84; i++) {
		ll x = fib[fib.size() - 2] + fib[fib.size() - 1];
		fib.push_back(x);
	}

	// 0 .. 85

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		vector<int> v;
		for (int i = 85; i >= 0; i--) {
			if (fib[i] <= x) {
				x -= fib[i];
				v.push_back(i);
			}
		}

		ll pup = 1;
		ll ne = 1;

		reverse(v.begin(), v.end());

		pup = v[0] / 2;

		for (int i = 1; i < (int)v.size(); i++) {
			int a = v[i - 1];
			int b = v[i];

			ll pup_n = pup * ((b - a) / 2) + ne * ((b - a - 1) / 2);
			ll ne_n = pup + ne;

			ne = ne_n;
			pup = pup_n;
		}

		cout << ne + pup << '\n';
	}

}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}