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
		map<int, basic_string<int>> e;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			e[x] += i;
		}
		int sol = 1e9;
		for (auto [k, v] : e) {
			int c=0;
			if (v[0] > 0) c++;
			for (int i=0; i<(int)v.size()-1; i++) {
				if (v[i+1] - v[i] > 1) c++;
			}
			if (v.back() < n-1) c++;
			sol = min(sol, c);
		}
		cout << sol << '\n';
	}
}