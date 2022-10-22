#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		if (n==1) {
			cout << -1 << '\n';
			continue;
		}
		cout << 2;
		for (int i=1; i<n; i++) cout << 3;
		cout << '\n';
	}
}