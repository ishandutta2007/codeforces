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

	int n, lo = 1123123123, hi = -1;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		lo = min(lo, x);
		hi = max(hi, x);
	}
	cout << hi-lo-n+1 << '\n';
}