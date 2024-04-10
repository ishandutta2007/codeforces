#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

const int MM = (1 << 9);

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	//cout << (240 | 170) << endl;
	int n, m;
	cin >> n >> m;
	vector<int> b(MM);
	for (int i = 0; i < n; i++) {
		int f; cin >> f;
		int t;
		int mask = 0;
		while (f--) {
			cin >> t; t--;
			mask |= (1 << t);
		}
		b[mask]++;
	}
	vector<vector<pair<int, int>>> a(MM);
	for (int i = 0; i < m; i++) {
		int c;  cin >> c;
		int r; cin >> r;
		int t;
		int mask = 0;
		while (r--) {
			cin >> t; t--;
			mask |= (1 << t);
		}
		//cout << mask << endl;
		a[mask].push_back({ c, i + 1});
	}
	for (int mask = 0; mask < MM; mask++) sort(a[mask].begin(), a[mask].end());
	vector<pair<int, pair<int, int>>> two_pizzas(MM, { INFi, {-1, -1} });
	for (int i = 0; i < MM; i++) {
		if (a[i].empty()) continue;
		if (a[i].size() > 1) {
			if (two_pizzas[i].first > a[i][0].first + a[i][1].first) two_pizzas[i] = { a[i][0].first + a[i][1].first,{a[i][0].second, a[i][1].second} };
		}
		for (int j = i + 1; j < MM; j++) {
			if (a[j].empty()) continue;
			int nmask = i | j;
			if (two_pizzas[nmask].first > a[i][0].first + a[j][0].first) two_pizzas[nmask] = { a[i][0].first + a[j][0].first,{ a[i][0].second, a[j][0].second } };
		}
	}
	/*for (int i = 0; i < MM; i++) {
		cout << i << " " << two_pizzas[i].second.first << " " << two_pizzas[i].second.second << endl;
	}*/
	int cnt = 0;
	int cost = INFi;
	int ans = 0;
	for (int mask = 0; mask < MM; mask++) {
		int cur = 0;
		if (two_pizzas[mask].first == INFi) continue;
		for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
			cur += b[sub];
		}
		//cout << mask << " " << cur << endl;
		if (cur > cnt || (cur == cnt && cost > two_pizzas[mask].first)) {
			ans = mask;
			cnt = cur;
			cost = two_pizzas[mask].first;
		}
	}
	//cout << ans << endl;
	cout << two_pizzas[ans].second.first << " " << two_pizzas[ans].second.second << endl;
	//system("pause");
	return 0;
}