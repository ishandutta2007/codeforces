#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	ll sol = 0;
	cin >> s;
	int n = s.size();
	vector<int> a(n-1), b(n-1), c(n-1);
	for (int i=0; i<n-1; i++)
		a[i] = s[i] == 'v' && s[i+1] == 'v';
	partial_sum(a.begin(), a.end(), b.begin());
	partial_sum(a.rbegin(), a.rend(), c.rbegin());
	for (int i=1; i<n-2; i++) {
		if (s[i] == 'o') {
			sol += 1ll*b[i-1]*c[i+1];
		}
	}
	cout << sol << '\n';
}