#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[105], b[105];
int c[105][105], n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=m; i++)
		cin >> b[i];

	int x = accumulate(a+1, a+n+1, 0, bit_xor<int>());
	int y = accumulate(b+1, b+m+1, 0, bit_xor<int>());

	if (x != y)
		return cout << "NO\n", 0;

	cout << "YES\n";
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (i < n && j < m)
				cout << "0 ";
			else if (i == n && j < m)
				cout << b[j] << ' ';
			else if (i < n && j == m)
				cout << a[i] << ' ';
			else
				cout << (x ^ a[i] ^ b[j]) << ' ';
		}
		cout << '\n';
	}
}