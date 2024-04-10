#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++)
		cin >> b[i];

	if (m == 1) {
		cout << n << '\n';
		return 0;
	}
	
	vector<int> v;

	for (int j=0; j<m-1; j++)
		v.push_back(b[j+1] - b[j]);

	v.push_back(2000000001);

	for (int i=0; i<n-1; i++)
		v.push_back(a[i+1] - a[i]);

	// z-algo
	int k = (int)v.size();
	vector<int> z(k, 0);
	for (int i=1, l=0, r=0; i<k; i++) {
		if (i < r)
			z[i] = min(r-i, z[i-l]);
		while (i + z[i] < k && v[i + z[i]] == v[z[i]])
			z[i]++;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	int sol = 0;

	for (int i=1; i<k; i++)
		if (z[i] == m-1)
			sol++;

	cout << sol << '\n';
}