#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, basic_string<int>> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	
	for (int i=1; i<=k; i++) {
		m[i & -i] += i;
	}

	basic_string<int> sol;

	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		while (it->second.size() && it->first <= n) {
			sol += it->second.back();
			it->second.pop_back();
			n -= it->first;
		}
	}

	if (n) {
		cout << "-1\n";
		return 0;
	}

	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x << ' ';
}