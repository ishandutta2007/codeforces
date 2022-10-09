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

	int n, m;
	cin >> n >> m;
	cout << n+m-1 << '\n';
	for (int i=1; i<=m; i++)
		cout << "1 " << i << '\n';
	for (int i=2; i<=n; i++)
		cout << i << ' ' << m << '\n';
}