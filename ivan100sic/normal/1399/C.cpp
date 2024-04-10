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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
		}

		sort(begin(a), end(a));

		int z = 0;
		for (int s=2; s<=2*n; s++) {
			int c = 0, l = 0, r = n-1;
			while (l < r) {
				if (a[l] + a[r] == s) {
					c++;
					l++;
					r--;
				} else if (a[l] + a[r] > s) {
					r--;
				}	else {
					l++;
				}
			}
			z = max(z, c);
		}

		cout << z << '\n';
	}
}