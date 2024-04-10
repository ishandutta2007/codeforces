#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, c[105], sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x%k]++;
	}

	for (int i=0; i<k; i++) {
		int j = (k-i) % k;
		if (i < j) {
			sol += min(c[i], c[j]);
		} else if (i == j) {
			sol += c[i] / 2;
		}
	}

	cout << sol*2 << '\n';
}