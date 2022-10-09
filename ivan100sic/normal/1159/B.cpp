#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int z = 1123123123;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		if (i > 1)
			z = min(z, x / (i-1));
		if (i < n)
			z = min(z, x / (n-i));
	}

	cout << z << '\n';
}