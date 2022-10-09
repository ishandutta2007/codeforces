#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> a, b;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int t, x;
		cin >> t >> x;
		(t == 1 ? a : b) += x;
	}
	int x = a.size();
	int y = b.size();
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int sol = 123123123;
	for (int i=0; i<=x; i++) {
		for (int j=0; j<=y; j++) {
			int d = i + 2*j;
			int z = accumulate(a.begin()+i, a.end(), 0);
			z = accumulate(b.begin()+j, b.end(), z);
			if (z <= d) {
				sol = min(sol, d);
			}
		}
	}
	cout << sol << '\n';
}