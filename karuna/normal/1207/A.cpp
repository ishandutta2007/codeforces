#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int b, p, f, h, c, t;
int main() {
	cin >> t;
	while (t--) {
		cin >> b >> p >> f;
		cin >> h >> c;

		int ans = 0;
		if (h>c) {
			int tmp = min(b/2, p);
			ans += tmp*h;
			b -= tmp*2;
			p -= tmp;

			tmp = min(b/2, f);
			ans += tmp*c;
		}
		else {
			int tmp = min(b/2, f);
			ans += tmp*c;
			b -= tmp*2;
			f -= tmp;

			tmp = min(b/2, p);
			ans += tmp*h;
		}

		cout << ans << '\n';
	}
}