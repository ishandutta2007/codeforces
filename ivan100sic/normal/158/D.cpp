#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, s = -1123123123;
int a[20005];
int b[20005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int d=1; d<=n; d++) {
		if (n % d)
			continue;
		if (n/d < 3)
			continue;

		fill(b, b+d, 0);
		for (int i=0; i<n; i++)
			b[i % d] += a[i];
		s = max(s, *max_element(b, b+d));
	}
	cout << s << '\n';
}