#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > v, lv[100009];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > st;
int ans[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int pc = 0;
	bool f = true;
	for (int i = 0; i < 2 * n; i++) {
		char c; cin >> c;
		if (c == '+') pc++;
		else {
			int a; cin >> a;
			int pr = 0;
			while (!v.empty() && v.back().first < a) v.pop_back();
			if (!v.empty()) pr = v.back().second;
			v.push_back(make_pair(a, pc));
			lv[pr + 1].push_back(make_pair(pc, a));
			if (!pc) f = false;
		}
	}
	if (!f) {
		cout << "NO" << '\n';
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < lv[i].size(); j++)
			st.push(lv[i][j]);
		while (!st.empty() && st.top().first < i)
			st.pop();
		if (st.empty()) {
			cout << "NO" << '\n';
			return 0;
		}
		ans[i] = st.top().second;
		st.pop();
	}
	cout << "YES" << '\n';
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}