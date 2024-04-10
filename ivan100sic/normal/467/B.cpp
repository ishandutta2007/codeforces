#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k, z;
int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<=m; i++)
		cin >> a[i];
	for (int i=0; i<m; i++) {
		if (__builtin_popcount(a[i] ^ a[m]) <= k)
			z++;
	}
	cout << z << '\n';
}