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
	for (int i=0; i<(1<<n); i++) {
		for (int j=0; j<(1<<n); j++) {
			cout << "+*"[__builtin_parity(i&j)];
		}
		cout << '\n';
	}
}