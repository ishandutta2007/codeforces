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
		int n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		ll d0 = b, d1 = 1e18;
		for (int i=0; i<n; i++) {
			char c = s[i];
			char sl = i < n-1 ? s[i+1] : '0';
			ll p0 = min(d0+a, d1+a+a) + b;
			ll p1 = min(d0+a+a, d1+a) + b+b;
			if (c == '1' || sl == '1')
				p0 = 1e18;
			d0 = p0;
			d1 = p1;
		}
		cout << d0 << '\n';
	}
}