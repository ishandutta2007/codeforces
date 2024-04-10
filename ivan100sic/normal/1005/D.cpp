#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];
int z[200005];
int d[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	n = s.size();
	for (int i=1; i<=n; i++)
		a[i] = s[i-1] - '0';

	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + a[i];

	d[0] = 0;

	for (int i=1; i<=n; i++) {
		for (int j=max(0, i-5); j<i; j++) {
			if (z[i] - z[j] == 0 && i-j > 1)
				continue;
			// deljiv sa 3?
			if ((z[i] - z[j]) % 3 == 0)
				d[i] = max(d[i], d[j] + 1);
			else
				d[i] = max(d[i], d[j]);
		}
	}

	cout << d[n] << '\n';
}