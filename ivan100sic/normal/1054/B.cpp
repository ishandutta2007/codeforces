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

	int n;
	cin >> n;
	int h = -1;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (x > h+1) {
			cout << i << '\n';
			return 0;
		}
		h = max(h, x);
	}
	cout << "-1\n";
}