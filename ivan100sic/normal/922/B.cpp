#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, u = 0;
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=i; j<=n; j++) {
			int k = i^j;
			if (i + j > k && k >= j && k <= n) {
				u++;
			}
		}
	}
	cout << u << '\n';
}