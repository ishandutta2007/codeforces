#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int inf = 1000000009;

vector<int> v[200009];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
int d[200009], r[200009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		r[a]++;
		v[b].push_back(a);
	}
	for (int i = 1; i < n; i++)
		d[i] = inf;
	q.push(make_pair(0, n));
	while (!q.empty()) {
		int hn = q.top().second, hl = q.top().first; q.pop();
		if (hl != d[hn]) continue;
		for (int i = 0; i < v[hn].size(); i++) {
			int tn = v[hn][i];
			if (d[hn] + r[tn] < d[tn]) {
				d[tn] = d[hn] + r[tn];
				q.push(make_pair(d[tn], tn));
			}
			r[tn]--;
		}
	}
	cout << d[1] << '\n';
	return 0;
}