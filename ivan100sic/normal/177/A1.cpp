#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int h = n/2+1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			int x;
			cin >> x;
			if (i == h || j == h || i == j || i+j == n+1)
				a += x;
		}
	cout << a << '\n';
}