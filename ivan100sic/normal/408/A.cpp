#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, y = 1123123123;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++) {
		int z = 0;
		for (int j=0; j<a[i]; j++) {
			int x;
			cin >> x;
			z += 5 * x;
		}
		z += 15 * a[i];
		y = min(y, z);
	}
	cout << y << '\n';

}