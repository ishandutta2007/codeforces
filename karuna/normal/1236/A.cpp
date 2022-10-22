#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int t, a, b, c;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> a >> b >> c;

		int ans = 0;
		ans += min(b, c/2); b -= ans;
		ans += min(a, b/2);

		cout << 3*ans << '\n';
	}
}