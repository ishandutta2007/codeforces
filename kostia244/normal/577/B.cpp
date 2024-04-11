#include <bits/stdc++.h>
using namespace std;

int n, m, t;
set<int> a;

int main() {
	cin >> n >> m;

	a.insert(0);
	for(int i = 0; i < n; i++) {
		cin >> t;
		set<int> ts;
		for(auto j : a) {
			if((j + t)%m == 0) {
				cout << "YES";
				return 0;
			}
			ts.insert((j + t)%m);
		}
		a.insert(ts.begin(), ts.end());
	}
	cout << "NO";
	return 0;
}