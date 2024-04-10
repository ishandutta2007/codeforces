#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll m;
	cin >> m;
	m--;

	int l = 0, r = n-1, j = 0;
	for (int i=n-2; i>=0; i--) {
		if (m & (1ll << i))
			a[r--] = ++j;
		else
			a[l++] = ++j;
	}
	a[l] = n;
	for (int i=0; i<n; i++)
		cout << a[i] << ' ';
	cout << '\n';;
}