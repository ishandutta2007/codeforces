#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sol;
int a[2005];
int c[2005];
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		mp[a[i]] = 0;
	}
	int j = 0;
	for (auto& [x, y] : mp)
		y = ++j;
	for (int i=1; i<=n; i++)
		a[i] = mp[a[i]];

	if (j == n) {
		cout << "0\n";
		return 0;
	}

	int z = n;

	for (int l=1; l<=n; l++) {
		memset(c, 0, sizeof(c));
		bool ok = true;
		for (int j=1; j<l; j++)
			ok &= (++c[a[j]] == 1);
		for (int r=n; r>=l; r--) {
			if (ok)
				z = min(z, r-l+1);
			ok &= (++c[a[r]] == 1);
		}
	}

	cout << z << '\n';
}