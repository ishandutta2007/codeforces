#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], p[100005], s[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		a[l]++;
		a[r+1]--;
	}
	for (int i=1; i<=m; i++)
		a[i] += a[i-1];

	vector<int> b = {-1};
	for (int i=1; i<=m; i++) {
		auto it = upper_bound(b.begin(), b.end(), a[i]);
		// cerr << "seek " << i << ' ' << a[i] << ' ' << it - b.begin() << '\n';
		if (it == b.end()) {
			b.push_back(a[i]);
		} else {
			*it = a[i];
		}
		p[i] = b.size() - 1;
	}

	b = {-1};
	for (int i=m; i>=1; i--) {
		auto it = upper_bound(b.begin(), b.end(), a[i]);
		if (it == b.end()) {
			b.push_back(a[i]);
		} else {
			*it = a[i];
		}
		s[i] = b.size() - 1;
	}

	int z = 0;
	for (int i=1; i<=m; i++) {
		// cerr << i << ' ' << p[i] << ' ' << s[i] << '\n';
		z = max(z, p[i] + s[i] - 1);
	}
	cout << z << '\n';
}