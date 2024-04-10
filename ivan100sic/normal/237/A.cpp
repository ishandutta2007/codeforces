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

	map<int, int> s;
	int n, sol=0;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		sol = max(sol, ++s[123*x+y]);
	}
	cout << sol << '\n';
}