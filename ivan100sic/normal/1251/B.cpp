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

	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		int p=0, q=0;
		vector<int> a;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			a.push_back(s.size());
			p += count(s.begin(), s.end(), '0');
			q += count(s.begin(), s.end(), '1');
		}
		// ne moze sve?
		int r = 0;
		for (int i=0; i<n; i++)
			r += a[i] % 2;
		if (r == 0 && p % 2 == 1)
			cout << n-1 << '\n';
		else
			cout << n << '\n';
	}
}