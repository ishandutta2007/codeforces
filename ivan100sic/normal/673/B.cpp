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

	int n, m;
	cin >> n >> m;
	int l = 1, r = n-1;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		l = max(l, x);
		r = min(r, y-1);
	}
	cout << max(0, r-l+1) << '\n';
}