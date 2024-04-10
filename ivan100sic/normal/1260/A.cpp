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
		int s, c;
		cin >> c >> s;

		int q = s / c;
		int r = s % c;
		cout << q*q*(c-r) + (q+1)*(q+1)*r << '\n';
	}
}