#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, m;
int a[1000005];
bool v[1000005];
string s;
int f[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	m = s.size();

	for (int i=0; i<k; i++)
		cin >> a[i];

	f[0] = -1;
	f[1] = 0;
	for (int i=2; i<=m; i++) {
		int z = f[i-1];
		while (z >= 0 && s[z] != s[i-1])
			z = f[z];
		f[i] = z + 1;
	}

	for (int z=m; z; z=f[z])
		v[z] = true;

	int cnt;

	if (k == 0) {
		cnt = n;
	} else {
		// ima resenja?
		for (int i=0; i<k-1; i++) {
			int d = a[i+1] - a[i];
			if (d < m && !v[m-d])
				return cout << "0\n", 0;
		}

		cnt = a[0] - 1;
		for (int i=0; i<k-1; i++) {
			cnt += max(0, a[i+1] - a[i] - m);
		}
		cnt += max(0, n - a[k-1] - m + 1);
	}

	int sol = 1;
	while (cnt--) {
		sol = sol * 26ll % 1000000007;
	}
	cout << sol << '\n';
}