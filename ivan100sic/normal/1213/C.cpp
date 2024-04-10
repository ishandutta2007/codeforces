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
		ll a, b;
		cin >> a >> b;
		ll s = (a/b)/10, p=0, q=0;
		for (ll i=0; i<10; i++)
			p += i*b%10;
		for (ll i=1; i<=(a/b)%10; i++)
			q += i*b%10;
		cout << s*p + q << '\n';
	}
}