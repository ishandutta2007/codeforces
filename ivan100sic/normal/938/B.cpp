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

	basic_string<int> a = {1};
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		a += x;
	}
	a += 1'000'000;
	int sol = 1131231232;
	for (int i=0; i<(int)a.size()-1; i++) {
		sol = min(sol, max(a[i] - 1, 1000000 - a[i+1]));
	}
	cout << sol << '\n';
}