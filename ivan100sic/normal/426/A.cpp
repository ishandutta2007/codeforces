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

	int n, s;
	cin >> n >> s;
	int z=0, h=0;
	while (n--) {
		int x;
		cin >> x;
		z += x;
		h = max(h, x);
	}
	z -= h;
	cout << (z <= s ? "YES\n" : "NO\n");
}