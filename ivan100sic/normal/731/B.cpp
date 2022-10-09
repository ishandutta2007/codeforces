#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int no = 0, z = 0;

	for (int i=1; i<=n; i++) {
		if (a[i] == 0) {
			if (z % 2)
				no = 1;
			z = 0;
		} else {
			z += a[i];
		}
	}

	if (z % 2)
		no = 1;

	cout << (no ? "NO\n" : "YES\n");
}