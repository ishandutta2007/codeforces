#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> a(n);
	int s, d, c;
	vector<pair<int, int>> exx(m);
	for(int i = 0; i < m; i++) {
		cin >> s >> d >> c; s--; d--;
		a[d].push_back({-1, i });
		a[s].push_back({1, i });
		exx[i] = { c, d };
	}
	set<pair<int, int>> f;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		sort(a[i].begin(), a[i].end());
		bool fl = false;
		for (auto j : a[i]) {
			//cout << i << " " << j.first << " " << j.second << endl;
			if (j.first == -1 && exx[j.second].first != 0) {
				cout << -1 << endl;
				//system("pause");
				return 0;
			}
			else if (j.first == 1) {
				f.insert({ exx[j.second].second, j.second });
			}
			else {
				ans[i] = m + 1;
				fl = true;
			}
		}
		if (!fl) {
			if (f.empty()) ans[i] = 0;
			else {
				auto h = *f.begin();
				ans[i] = h.second + 1;
				exx[h.second].first--;
				if (exx[h.second].first == 0) {
					f.erase(f.begin());
				}
			}
		}
	}
	for (int i : ans) {
		cout << i << " ";
	}
	//system("pause");
	return 0;
}