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

	int n, sol;
	cin >> n;
	sol = 100000;
	for (int i=1; i<=100000; i++) {
		sol = min(sol, i + (n+i-1) / i);
	}
	cout << sol << '\n';
}