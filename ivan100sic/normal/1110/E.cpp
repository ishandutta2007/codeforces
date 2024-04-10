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
	basic_string<int> a(n, 0), b(n, 0), c, d;
	for (int& x : a)
		cin >> x;
	for (int& x : b)
		cin >> x;

	for (int i=0; i<n-1; i++) {
		c += a[i+1] - a[i];
		d += b[i+1] - b[i];
	}

	sort(c.begin(), c.end());
	sort(d.begin(), d.end());

	cout << ((c == d && a[0] == b[0] && a[n-1] == b[n-1]) ? "Yes\n" : "No\n");
}