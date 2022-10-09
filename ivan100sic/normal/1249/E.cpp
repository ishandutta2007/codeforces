#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c;
int a[200005], b[200005], x[200005], y[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;

	for (int i=0; i<n-1; i++)
		cin >> a[i], a[i] *= 2;
	for (int i=0; i<n-1; i++)
		cin >> b[i], b[i] *= 2;

	x[0] = 0, y[0] = c;

	cout << 0;
	for (int i=1; i<n; i++) {
		x[i] = x[i-1] + a[i-1];
		y[i] = y[i-1] + b[i-1];

		x[i] = min(x[i], y[i]+c);
		y[i] = min(y[i], x[i]+c);

		cout << ' ' << (x[i] >> 1);
	}
	cout << '\n';

}