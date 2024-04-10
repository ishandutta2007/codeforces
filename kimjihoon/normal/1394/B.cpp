#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > v[200009], pv[19][19];
vector<int> r[19][19];
bool vs[200009], rm[19][19], pm[19][19];
int kp, ans = 0;

void ps(int pi)
{
	if (pi > kp) {
		ans++;
		return;
	}
	for (int i = 0; i < pi; i++) {
		bool f = false;
		if (rm[pi][i]) continue;
		for (int j = 0; j < pv[pi][i].size(); j++)
			if (pm[pv[pi][i][j].first][pv[pi][i][j].second]) {
				f = true;
				break;
			}
		if (f) continue;
		pm[pi][i] = true;
		ps(pi + 1);
		pm[pi][i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n, m; cin >> n >> m >> kp;
	for (int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		v[a].push_back(make_pair(w, b));
	}
	for (int i = 1; i <= n; i++)
		if (v[i].empty()) {
			cout << 0 << '\n';
			return 0;
		}
	for (int i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++)
			r[v[i].size()][j].push_back(v[i][j].second);
	}
	for (int i = 1; i <= kp; i++)
		for (int j = 0; j < i; j++) {
			for (int k = 0; k <= n; k++)
				vs[k] = false;
			
			for (int k = 0; k < r[i][j].size(); k++) {
				if (vs[r[i][j][k]]) {
					rm[i][j] = true;
					break;
				}
				vs[r[i][j][k]] = true;
			}
			if (rm[i][j]) continue;
			for (int ti = i + 1; ti <= kp; ti++)
				for (int tj = 0; tj < ti; tj++) {
					bool f = false;
					for (int k = 0; k < r[ti][tj].size(); k++)
						if (vs[r[ti][tj][k]]) {
							f = true;
							break;
						}
					if (f)
						pv[ti][tj].push_back(make_pair(i, j));
				}
		}
	ps(1);
	cout << ans << '\n';
	return 0;
}