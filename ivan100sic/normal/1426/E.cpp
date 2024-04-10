// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, a[3], b[3];
	cin >> n;
	cin >> a[0] >> a[1] >> a[2];
	cin >> b[0] >> b[1] >> b[2];

	int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
	int mn = max({0, a[0] - b[0] - b[2], a[1] - b[1] - b[0], a[2] - b[2] - b[1]});

	cout << mn << ' ' << mx << '\n';
}