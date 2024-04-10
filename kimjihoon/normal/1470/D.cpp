#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[300009], ans;
int r[300009];
queue<int> q, tq, rq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			r[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int a, b; cin >> a >> b;
			v[a].push_back(b); v[b].push_back(a);
		}
		tq.push(1); r[1] = 1;
		while (!tq.empty() || !rq.empty() || !q.empty()) {
			if (!tq.empty()) {
				int hn = tq.front(); tq.pop();
				for (int i = 0; i < v[hn].size(); i++) {
					int tn = v[hn][i];
					if (!r[tn]) {
						q.push(tn); r[tn] = 2;
					}
				}
				continue;
			}
			if (!rq.empty()) {
				int hn = rq.front(); rq.pop();
				if (!r[hn]) {
					tq.push(hn);
					r[hn] = 1;
				}
				continue;
			}
			int hn = q.front(); q.pop();
			for (int i = 0; i < v[hn].size(); i++) {
				int tn = v[hn][i];
				if (!r[tn]) {
					if (tq.empty()) {
						tq.push(tn);
						r[tn] = 1;
					}
					else {
						rq.push(tn);
					}
				}
			}
		}
		ans.clear();
		bool f = true;
		for (int i = 1; i <= n; i++) {
			if (!r[i]) {
				f = false;
				break;
			}
			if (r[i] == 1) ans.push_back(i);
		}
		if (!f) {
			cout << "NO" << '\n';
			continue;
		}
		cout << "YES" << '\n';
		sort(ans.begin(), ans.end());
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << '\n';
	}
	return 0;
}