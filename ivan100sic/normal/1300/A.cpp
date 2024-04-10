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
		int n, z = 0;
		cin >> n;
		vector<int> a(n);
		for (int& x : a) {
			cin >> x;
			if (x == 0) {
				x = 1;
				z++;
			}
		}

		int s = accumulate(begin(a), end(a), 0);
		if (s == 0) {
			z++;
		}

		cout << z << '\n';
	}
}