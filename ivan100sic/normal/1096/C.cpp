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

	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int found = 0;
		for (int n=3; n<=360; n++) {
			for (int p=1; p<n-1; p++) {
				if (x * n == p * 180) {
					cout << n << '\n';
					found = 1;
					n = 361;
				}
			}
		}
		if (!found)
			cout << "-1\n";
	}
}