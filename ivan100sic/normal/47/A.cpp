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
	for (int i=1; i<=1000; i++) {
		if (i*(i+1) / 2 == n) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}