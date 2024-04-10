#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z;
int a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		int x, y, z, t;
		x = i;
		y = a[x];
		z = a[y];
		t = a[z];
		if (set<int>({x, y, z}).size() == 3 && x == t) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}