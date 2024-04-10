#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
string s;
int z[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> s;
	n = s.size();
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + (s[i] == '1');
	int r = 0, p = 0;
	ll sol = 0;
	for (int l=0; l<n; l++) {
		r = max(l, r);
		p = max(l, p);
		while (r <= n && z[r] - z[l] < k) r++;
		while (p <= n && z[p] - z[l] <= k) p++;
		sol += p - r;
		if (r == l)
			sol--;
	}
	cout << sol << '\n';
}