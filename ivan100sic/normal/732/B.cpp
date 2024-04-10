#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, sol;
int b[505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int last = k;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x + last < k) {
			int d = k - x - last;
			sol += d;
			x += d;
		}
		last = x;
		b[i] = x;
	}
	cout << sol << '\n';
	for (int i=1; i<=n; i++)
		cout << b[i] << ' ';
	cout << '\n';
}