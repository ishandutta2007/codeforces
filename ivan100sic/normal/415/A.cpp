#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		int x;
		cin >> x;
		for (int i=x; i<=n; i++)
			if (!a[i])
				a[i] = x;
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}