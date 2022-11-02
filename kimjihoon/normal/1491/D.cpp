#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v0, v1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int a, b; cin >> a >> b;
		if (a == b) {
			cout << "YES" << '\n';
			continue;
		}
		if (a > b) {
			cout << "NO" << '\n';
			continue;
		}
		v0.clear(); v1.clear();
		for (int i = 0; i < 30; i++) {
			if ((1 << i) & a) v0.push_back(i);
			if ((1 << i) & b) v1.push_back(i);
		}
		if (v0.size() < v1.size()) {
			cout << "NO" << '\n';
			continue;
		}
		while (!v0.empty() && !v1.empty() && v0.back() == v1.back()) {
			v0.pop_back();
			v1.pop_back();
		}
		if (v0.empty() || v1.empty() || v0.back() > v1.back()) {
			cout << "NO" << '\n';
			continue;
		}
		bool f = true;
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] < v0[i]) {
				f = false;
				break;
			}
		}
		if (f) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}