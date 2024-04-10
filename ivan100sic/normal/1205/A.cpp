#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		a[i] = 2*i-1;
		a[i+n] = 2*i;
		if (i % 2 == 0)
			swap(a[i], a[i+n]);
	}
	for (int i=1; i<=2*n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}