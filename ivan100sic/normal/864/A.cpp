#include <bits/stdc++.h>
using namespace std;

map<int, int> c;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c[x]++;
	}

	if (c.size() == 2 && c.begin()->second == next(c.begin())->second) {
		cout << "YES\n" << c.begin()->first << ' ' << next(c.begin())->first;
	} else {
		cout << "NO\n";
	}
}