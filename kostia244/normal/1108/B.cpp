#include <bits/stdc++.h>
using namespace std;

int n, t, r1, r2;
vector<int> a, b;
vector<bool> c;
map<int, bool> g;

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());
	r1 = a.back();
	for(int i = 0; i < (n - 1); i++) {
		if((r1%a[i] == 0 && (r1 != a[i])) && !g[a[i]]) {
			g[a[i]] = true;
		} else {
			b.push_back(a[i]);
		}
	}
	sort(b.begin(), b.end());
	cout << r1 << " " << b.back();
}