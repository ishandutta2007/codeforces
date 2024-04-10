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

	int n;
	cin >> n;
	basic_string<int> a(n, 0);
	for (int& x : a)
		cin >> x;
	sort(a.begin(), a.end());

	int x = a[0];
	int y = a[0];
	basic_string<int> f, b;
	f += x;
	for (int i=1; i<n; i++) {
		if (x < y) {
			x = a[i];
			f += x;
		} else {
			y = a[i];
			b += y;
		}
	}
	reverse(b.begin(), b.end());
	f += b;
	for (int x : f)
		cout << x << ' ';
	cout << '\n';
}