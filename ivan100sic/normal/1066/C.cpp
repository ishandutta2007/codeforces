#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, multiset<int>> pos;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q, l = 0, r = 1;
	cin >> q;
	while (q--) {
		char x; int y;
		cin >> x >> y;
		if (x == 'L')
			pos[y].insert(l--);
		else if (x == 'R')
			pos[y].insert(r++);
		else {
			cout << min(*pos[y].begin() - l, r - *pos[y].rbegin())-1 << '\n';
		}
	}
}