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
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		int s = 0;
		s = max(s, a * (b-y-1));
		s = max(s, a * y);
		s = max(s, b * (a-x-1));
		s = max(s, b * x);
		cout << s << '\n';
	}
}