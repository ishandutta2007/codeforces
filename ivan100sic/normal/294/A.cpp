#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int q;
	cin >> q;
	while (q--) {
		int i, y;
		cin >> i >> y;
		a[i-1] += y-1;
		a[i+1] += a[i] - y;
		a[i] = 0;
	}

	for (int i=1; i<=n; i++) {
		cout << a[i] << '\n';
	}

}