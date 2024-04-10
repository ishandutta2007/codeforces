#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
int main() {
	int n, a[200000];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	ll ans = abs(a[0]);
	for (int i = 1; i < n; ++i) {
		ans += abs(a[i] - a[i - 1]);
	}
	cout << ans << '\n';
}