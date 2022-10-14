#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, s;
	cin >> s >> n;
	vector<pair<int, int>> a(n);
	for(auto &[x, y] : a) cin >> x >> y;
	sort(a.begin(), a.end());
	for(auto [x, y] : a) {
		if(s > x) s += y;
		else s = -1;
	}
	cout << (s == -1 ? "NO" : "YES") << '\n';
}