#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, d;
int a[1005], c[1005], z[1005], s[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	for (int i=0; i<m; i++)
		cin >> c[i];
	for (int i=m-1; i>=0; i--)
		z[i] = z[i+1] + c[i];

	int p = 0;
	for (int i=0; i<m; i++) {
		int r = min(n+1-z[i], p+d);
		fill(s+r, s+r+c[i], i+1);
		p = r+c[i]-1;
	}

	if (p+d >= n+1) {
		cout << "YES\n";
		for (int i=1; i<=n; i++)
			cout << s[i] << " \n"[i == n];
	} else {
		cout << "NO\n";
	}
		
}