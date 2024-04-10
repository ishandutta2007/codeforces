#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int d[105], z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> d[i];
		z += d[i];
	}
	int x, y;
	cin >> x >> y;
	x--, y--;
	if (x > y)
		swap(x, y);
	int f = accumulate(d+x, d+y, 0);
	cout << min(f, z-f) << '\n';
}