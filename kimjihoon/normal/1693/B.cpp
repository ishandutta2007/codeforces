#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v[200009];
int l[200009], r[200009], ans;
long long d[200009];

void dfs(int n)
{
	long long s = 0;
	for (int i = 0; i < v[n].size(); i++) {
		int tn = v[n][i];
		dfs(tn);
		s += d[tn];
	}
	if (s < l[n]) {
		ans++;
		d[n] = r[n];
	}
	else if (r[n] < s)
		d[n] = r[n];
	else
		d[n] = s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			v[i].clear();
		for (int i = 2; i <= n; i++) {
			int a; cin >> a;
			v[a].push_back(i);
		}
		for (int i = 1; i <= n; i++)
			cin >> l[i] >> r[i];
		ans = 0;
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}