// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];

		vector<vector<int>> el(2*k+2);
		vector<int> zz(2*k+5);

		for (int i=0; i<n/2; i++) {
			int s = a[i] + a[n-i-1];
			int l = min(a[i], a[n-i-1]);
			int h = s - l;
			el[s].push_back(l);
			zz[l+1]++;
			zz[h+k+1]--;
		}

		for (int i=1; i<2*k+5; i++)
			zz[i] += zz[i-1];

		int sol = 1e9;

		for (int x=1; x<=2*k; x++) {
			int d0 = el[x].size();
			int d1 = zz[x] - d0;
			int d2 = n/2 - d0 - d1;
			sol = min(sol, d1 + 2*d2);
		}

		cout << sol << '\n';
	}
}