#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, b, ax, bx;

void generisi(vector<int>& a, vector<int>& ax) {
	int n = a.size();
	ax.resize(1 << n);
	for (int mask=0; mask<(1 << n); mask++) {
		int sum = 0;
		for (int i=0; i<n; i++) {
			if (mask & (1<<i)) {
				sum += a[i];
				if (sum >= m) {
					sum -= m;
				}
			}
		}
		ax[mask] = sum;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		(i % 2 ? a : b).push_back(x % m);
	}

	generisi(a, ax);
	generisi(b, bx);

	int sol = 0;

	sort(bx.begin(), bx.end());

	for (int x : ax) {
		int kand = x;

		// cerr << "!" << x << '\n';

		auto it = lower_bound(bx.begin(), bx.end(), m-x);
		// m-x > 0 i 0 je uvek u b dakle it != b.begin()
		--it;

		kand += *it;
		if (kand >= m) {
			kand -= m;
		}
		sol = max(sol, kand);

		kand = x + bx.back();
		if (kand >= m) {
			kand -= m;
		}
		sol = max(sol, kand);
	}

	cout << sol;

}