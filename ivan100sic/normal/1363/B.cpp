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
		string s;
		cin >> s;
		int n = s.size();
		int sol = n;
		for (int i=0; i<=n; i++) {
			int a = count(begin(s), begin(s) + i, '0');
			int b = i - a;
			int c = count(begin(s) + i, end(s)  , '0');
			int d = n - i - c;

			sol = min({sol, a+d, b+c});
		}
		cout << sol << '\n';
	}
}