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

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> k(n);
	ll tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> k[i];
		tot += k[i];
	}
	//cout << tot << endl;
	vector<vector<int>> st(n);
	int t1, t2;
	for (int i = 0; i < m; i++) {
		cin >> t1 >> t2; t1--; t2--;
		st[t2].push_back(t1);
	}
	int l = -1;
	int r = 1e6;
	for (int i = 0; i < n; i++) {
		sort(st[i].begin(), st[i].end());
	}
	while (r - l > 1) {
		int mid = (r + l) / 2;
		vector<pair<int, int>> act;
		//cout << mid << endl;
		for (int i = 0; i < n; i++) {
			//cout << i << endl;
			if (st[i].empty()) continue;
			int le = 0;
			int re = st[i].size();
			while (re - le > 1) {
				int midd = (re + le) / 2;
				if (st[i][midd] <= mid) le = midd;
				else re = midd;
			}
			if (st[i][le] <= mid) act.push_back({ st[i][le], i });
		}
		int cnt = 0;
		int tot1 = tot;
		if (!act.empty()) {
			sort(act.begin(), act.end());
			//cout << l << " " << r << endl;
			for (int i = 0; i < act.size(); i++) {
				//if (mid == 0) cout << act[i].first << " " << act[i].second << endl;
				if (i == 0) cnt = act[i].first + 1;
				else cnt += act[i].first - act[i - 1].first;
				int bt = min(cnt, k[act[i].second]);
				cnt -= bt;
				tot1 -= bt;
				//if (mid == 0) cout << cnt  << " "  << tot1<< endl;
			}
			//cout << mid - act[act.size() - 1].first << "  flex\n";
			cnt += mid - act[act.size() - 1].first;
		}
		cnt -= 2 * tot1;
		//cout << cnt << endl;
		if (cnt < 0) l = mid;
		else r = mid;
	}
	cout << r + 1 << endl;
	//system("pause");
	return 0;
}