#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int& x : a) {
		cin >> x;
	}
	for (int& y : b) {
		cin >> y;
	}
	int sol = 123123;

	for (int x : a) {
		for (int y : b) {
			if (x == y) {
				sol = min(sol, x);
			} else {
				sol = min(sol, 10*x+y);
				sol = min(sol, 10*y+x);
			}
		}
	}

	cout << sol;
}