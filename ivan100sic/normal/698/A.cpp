// des Vlado

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int d[105][3];
int n, a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	memset(d, 63, sizeof(d));
	d[0][0] = 0;
	for (int i=1; i<=n; i++) {
		// odmaram?
		d[i][0] = min({d[i-1][0], d[i-1][1], d[i-1][2]}) + 1;
		// radim cf?
		if (a[i] & 1)
			d[i][1] = min({d[i-1][0], d[i-1][2]});
		if (a[i] & 2)
			d[i][2] = min({d[i-1][0], d[i-1][1]});
	}

	cout << *min_element(d[n], d[n]+3) << '\n';
}