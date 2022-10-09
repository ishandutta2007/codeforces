#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll broj(string s) {
	ll c1=0, c2=0, c3=0, c4=0;
	for (char x : s) {
		if (x == '1') {
			c1++;
		} else if (x == '3') {
			c3 += c2;
			c2 += c1;
		} else {
			c4 += c3;
		}
	}
	return c4;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;

		string mid = string(40, '1') + string(40, '3');
		string poc = "133";

		// cerr << broj(poc + mid + '7');

		int a = x / 32061;
		int b = x % 32061;

		string sol = poc + string(b, '7') + mid + string(a, '7');
		cout << sol << '\n';
		// cerr << broj(sol) << '\n';
	}
}