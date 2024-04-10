#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[5005];
int d[5005][5005];
int l[5005][5005];

vector<int> ksor(vector<int> z) {
	if (z.size() == 1)
		return z;
	vector<int> r(z.size() - 1);
	for (int i=0; i<(int)z.size()-1; i++)
		r[i] = z[i] ^ z[i+1];
	return ksor(r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];		
	
	for (int i=1; i<=n; i++)
		l[i][i] = d[i][i] = a[i];

	for (int i=n; i>=1; i--) {
		for (int j=i+1; j<=n; j++) {
			d[i][j] = d[i+1][j] ^ d[i][j-1];
		}
	}

	for (int i=n; i>=1; i--) {
		for (int j=i; j<=n; j++) {
			l[i][j] = max({d[i][j], l[i+1][j], l[i][j-1]});
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << ::l[l][r] << '\n';
	}
}