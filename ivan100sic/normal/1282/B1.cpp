#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// 0123456789
// abbbccc

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, p, k;
		cin >> n >> p >> k;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		sort(a.begin(), a.end());
		vector<int> ze(n+k), z(n+1);
		for (int i=n-1; i>=0; i--)
			ze[i] = ze[i+k] + a[i];
		for (int i=0; i<n; i++)
			z[i+1] = z[i] + a[i];
		int sol = 0;
		for (int i=1; i<=n; i++) {
			int c = z[i % k] + ze[i % k + k - 1] - ze[i + k - 1];
			if (c <= p)
				sol = i;
		}
		cout << sol << '\n';
	}
}