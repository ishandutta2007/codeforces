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

	int n, k;
	cin >> n >> k;
	if (n-1 < 2*k) {
		cout << "-1\n";
	} else {
		cout << n*k << '\n';
		for (int i=0; i<n; i++) {
			for (int j=0; j<k; j++) {
				cout << i+1 << ' ' << (i+j+1)%n+1 << '\n';
			}
		}
	}
}