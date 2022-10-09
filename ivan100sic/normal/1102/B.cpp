#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[5005], z[5005], n, k;
basic_string<int> e[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		e[a[i]] += i;
	}
	int y = 1;
	for (int i=1; i<=5000; i++) {
		if ((int)e[i].size() > k) {
			cout << "NO\n";
			return 0;
		}
		for (int x : e[i]) {
			z[x] = y++;
			if (y == k+1)
				y = 1;
		}
	}
	cout << "YES\n";
	for (int i=0; i<n; i++)
		cout << z[i] << " \n"[i == n];
}