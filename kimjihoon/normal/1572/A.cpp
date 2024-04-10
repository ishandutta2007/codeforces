#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int> > v[200009];
int id[200009], d[200009];
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			id[i] = 0;
			d[i] = -1;
		}
		for (int i = 1; i <= n; i++) {
			int k; cin >> k;
			for (int j = 0; j < k; j++) {
				int t; cin >> t;
				if (t < i) v[t].push_back(make_pair(i, 0));
				else v[t].push_back(make_pair(i, 1));
				id[i]++;
			}
		}
		while (!q.empty())
			q.pop();
		for (int i = 1; i <= n; i++) 
			if (!id[i]) {
				q.push(i);
				d[i] = 1;
			}
		while (!q.empty()) {
			int hn = q.front(); q.pop();
			for (int i = 0; i < v[hn].size(); i++) {
				int tn = v[hn][i].first, c = v[hn][i].second;
				d[tn] = max(d[tn], d[hn] + c);
				id[tn]--;
				if (!id[tn])
					q.push(tn);
			}
		}
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (id[i]) {
				ans = -1;
				break;
			}
			else
				ans = max(ans, d[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}