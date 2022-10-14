#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long

int n;
vector<pair<int, int>> pts, v;

bitset<10000> busy(0);
int px, py;

bool func(int k) {
	if (k >= n)
		return true;
	bool res = false;
	for (int i = 0; i < n; i++) {
		if (!busy.test(i)) {
			if (k == 0) {
				px = pts[k].first + v[i].first;
				py = pts[k].second + v[i].second;
			}
			if (px == (pts[k].first + v[i].first)
					&& py == (pts[k].second + v[i].second)) {
				busy.set(i, 1);
				res |= func(k + 1);
				if(k == 0 && res) {
					return true;
				}
				busy.set(i, 0);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	pts.resize(n);
	v.resize(n);

	for (auto& i : pts)
		cin >> i.first >> i.second;

	for (auto& i : v)
		cin >> i.first >> i.second;
	func(0);
	cout << px << " " << py;
}