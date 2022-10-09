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
	int l = 1, r = n*n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n/2; j++) {
			cout << l << ' ' << r << ' ';
			l++; r--;
		}
		cout << '\n';
	}
}