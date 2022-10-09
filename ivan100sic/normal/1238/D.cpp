// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
	string s;
	cin >> n >> s;
	int a = 0, b = 0;
	ll sol = n*(n-1ll) / 2;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A') {
			sol -= b;
			a = 1;
		} else {
			sol -= a;
			b = 1;
		}
	}
	reverse(begin(s), end(s));
	a = b = 0;
	for (int i=0; i<n; i++) {
		if (s[i] == 'A') {
			sol -= b;
			a = 1;
		} else {
			sol -= a;
			b = 1;
		}
	}
	for (int i=1; i<n; i++)
		sol += s[i] != s[i-1];
	cout << sol << '\n';
}

// I will still practice daily...