// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		int l = n*(a-b);
		int h = n*(a+b);
		if (max(l, c-d) <= min(h, c+d)) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}