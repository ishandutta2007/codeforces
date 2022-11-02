#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int, int> > v[200009];
pair<int, int> c[200009];
bool p[200009], vs[200009];
int ans[200009];

void dfs(int n, int r)
{
	vs[n] = true;
	int s = 0;
	if (p[n]) s = 1;
	for (int i = 0; i < v[n].size(); i++) {
		if (vs[v[n][i].first]) continue;
		if (!p[n]) {
			s++;
			if (s == r) s++;
		}
		ans[v[n][i].second] = s;
		dfs(v[n][i].first, s);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(make_pair(b, i)); v[b].push_back(make_pair(a, i));
		c[a].first++; c[b].first++;
	}
	for (int i = 1; i <= n; i++)
		c[i].second = i;
	sort(c + 1, c + n + 1);
	for (int i = n; i >= 1 && n - i < k; i--) 
		p[c[i].second] = true;
	cout << c[n - k].first << '\n';
	dfs(1, -1);
	for (int i = 1; i < n; i++)
		cout << ans[i] << " ";
	cout << '\n';
	return 0;
}