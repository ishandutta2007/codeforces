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
		int n;
		cin >> n;
		string s(n, '9');
		for (int i=0; i<(n+3)/4; i++) {
			s[n-1-i] = '8';
		}
		cout << s << '\n';
	}
}