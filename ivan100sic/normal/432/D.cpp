#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;
int f[100005];
int z[100005];
int c[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = (int)s.size();

	f[0] = -1;
	f[1] = 0;
	for (int i=2; i<=n; i++) {
		int z = f[i-1];
		while (z >= 0 && s[z] != s[i-1])
			z = f[z];
		f[i] = z + 1;
	}

	for (int i=1, l=0, r=0; i<n; i++) {
		if (i < r)
			z[i] = min(r-i, z[i-l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}

	z[0] = n;
	for (int i=0; i<n; i++)
		c[z[i]]++;
	for (int i=n-1; i>=0; i--)
		c[i] += c[i+1];

	vector<pair<int, int>> sol;
	for (int z=n; z; z=f[z]) {
		sol.push_back({z, c[z]});
	}

	reverse(sol.begin(), sol.end());

	cout << sol.size() << '\n';
	for (auto p : sol)
		cout << p.first << ' ' << p.second << '\n';
}