#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (c[x]++ == 2) {
			cout << "NO\n";
			return 0;
		}
	}
	basic_string<int> a, b;
	for (int i=0; i<=200000; i++) {
		if (c[i] > 0) {
			a += i;
			c[i]--;
		}
	}
	for (int i=200000; i>=0; i--) {
		if (c[i] > 0) {
			b += i;
			c[i]--;
		}
	}
	cout << "YES\n";
	cout << a.size() << '\n';
	for (int x : a)
		cout << x << ' ';
	cout << '\n' << b.size() << '\n';
	for (int x : b)
		cout << x << ' ';
	cout << '\n';
}