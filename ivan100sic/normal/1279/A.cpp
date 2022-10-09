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

	int t;
	cin >> t;
	while (t--) {
		ll r, g, b;
		cin >> r >> g >> b;
		ll h = max({r, g, b});
		if (h > r+g+b-h+1) {
			cout << "No\n";
		} else {
			cout << "Yes\n";
		}
	}	
}