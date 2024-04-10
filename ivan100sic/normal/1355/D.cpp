// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, s;
	cin >> n >> s;
	if (s >= 2*n) {
		cout << "YES\n";
		for (int i=0; i<n; i++) {
			cout << s/n + (i < s%n) << " \n"[i == n-1];
		}
		cout << "1\n";
	} else {
		cout << "NO\n";
	}
}