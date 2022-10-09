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

	basic_string<int> sol;
	int n, k;
	cin >> n >> k;
	basic_string<pair<int, int>> a;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a += {x, i};
	}
	sort(a.begin(), a.end());
	for (auto p : a) {
		if (p.first <= k) {
			k -= p.first;
			sol += p.second;
		}
	}
	cout << sol.size() << "\n";
	for (int x : sol)
		cout << x+1 << ' ';
	cout << '\n';
}