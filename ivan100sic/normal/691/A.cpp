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

	int n, z = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z += x;
	}
	cout << (((n == 1 && z == 1) || (n > 1 && z == n - 1)) ? "YES\n" : "NO\n");
}