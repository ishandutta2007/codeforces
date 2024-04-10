#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, basic_string<int>> bp;
int n;
string a, b;
basic_string<pair<int, int>> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;
	for (int i=0; i<n; i++) {
		bp[b[i]] += i;
	}

	for (int i=0; i<n; i++) {
		if (a[i] != '?') {
			if (bp[a[i]].size()) {
				sol += {i, bp[a[i]].back()};
				bp[a[i]].pop_back();
				a[i] = '.';
			}
		}
	}

	for (int i=0; i<n; i++) {
		if (a[i] != '?' && a[i] != '.') {
			if (bp['?'].size()) {
				sol += {i, bp['?'].back()};
				bp['?'].pop_back();
				a[i] = '.';
			}
		}
	}

	for (int i=0; i<n; i++) {
		if (a[i] == '?') {
			for (auto& p : bp) {
				if (p.second.size()) {
					sol += {i, p.second.back()};
					p.second.pop_back();
					a[i] = '.';
					break;
				}
			}
		}
	}

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x+1 << ' ' << y+1 << '\n';
}