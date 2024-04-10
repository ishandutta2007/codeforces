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

	int n;
	cin >> n;
	for (int i=1; i<=6; i++) {
		for (int j=1; j<=6; j++) {
			int k = n-i-j;
			if (k < 0)
				continue;
			if (i%3 && j%3 && k%3) {
				cout << i << ' ' << j << ' ' << k << '\n';
				return 0;
			}
		}
	}
}