#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int cvor[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;

	fill(cvor, cvor+k, 1);

	if ((n-1) % k == 0) {
		cout << 2 * ((n-1) / k) << '\n';
	} else if ((n-1) % k == 1) {
		cout << 2 * ((n-1) / k) + 1 << '\n';
	} else {
		cout << 2 * ((n-1) / k) + 2 << '\n';
	}

	for (int i=2; i<=n; i++) {
		cout << i << ' ' << cvor[i%k] << '\n';
		cvor[i%k] = i;
	}
}