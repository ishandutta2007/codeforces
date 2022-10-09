#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int i = 0, j = n+1;
	ll x=0, y=0, s=0;
	while (i < j) {
		if (x < y)
			x += a[++i];
		else if (x > y)
			y += a[--j];
		else {
			s = max(s, x);
			x += a[++i];
			y += a[--j];
		}
	}
	cout << s << '\n';
}