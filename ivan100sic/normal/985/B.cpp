#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int z[2005];
string a[2005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		for (int j=0; j<m; j++)
			z[j] += a[i][j] == '1';
	}

	for (int i=0; i<n; i++) {
		int k = 0;
		for (int j=0; j<m; j++) {
			if (z[j] - (a[i][j] == '1' ? 1 : 0) > 0)
				k++;
		}
		if (k == m)
			return cout << "YES\n", 0;
	}

	cout << "NO\n";
}