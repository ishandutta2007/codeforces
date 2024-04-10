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
	int sol = n;
	for (int i=1; i<=n/2; i++) {
		if (s.substr(0, i) == s.substr(i, i)) {
			sol = min(sol, n-i+1);
		}
	}
	cout << sol << '\n';
}