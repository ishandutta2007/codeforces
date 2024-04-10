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
typedef vector<vector<ll>> vll;

ll INF = 2e18 + 4;
int INFi = 2e9 + 2;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> ed(m);
	for (int i = 0; i < m; i++) {
		cin >> ed[i].second >> ed[i].first.first >> ed[i].first.second;
		ed[i].first.first--;
		ed[i].first.second--;
	}
	vector<pair<int, int>> st;
	for (auto u : ed) {
		if (u.second == 1) st.push_back({ u.first.first, u.first.second });
	}
	sort(st.begin(), st.end());
	int cur = -1;
	int f = 1100001;
	int h = f;
	vector<int> ans(n, -1);
	for (auto u : st) {
		if (u.second >= cur && cur >= u.first) {
			while (cur < u.second) {
				ans[++cur] = f;
			}
		}
		else if (cur > u.second) continue;
		else {
			h -= 1000;
			f = h;
			cur = u.first;
			while (cur <= u.second) {
				ans[cur++] = f;
			}
			cur--;
		}
	}
	f = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (ans[i] == -1) ans[i] = f++;
		else f = ans[i] + 1;
	}
	for (auto u : ed) {
		bool fl = true;
		for (int i = u.first.first + 1; i <= u.first.second; i++) {
			if (ans[i] < ans[i - 1]) {
				fl = false;
			}
		}
		if (u.second == 1 && !fl) {
			cout << "NO\n";
			return 0;
		}
		if (u.second == 0 && fl) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}