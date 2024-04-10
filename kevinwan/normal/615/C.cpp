#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h=203;
ll sh[3001][3001],th[3001][3001];
vector<pair<int, int>> v;
int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size(),i,j;
	for (i = 0; i < n; i++) {
		sh[i][i] = s[i];
		for (j = i + 1; j < n; j++)sh[i][j] = sh[i][j - 1] * h + s[j];
		for (j = i - 1; j >= 0; j--)sh[i][j] = sh[i][j + 1] * h + s[j];
	}
	for (i = 0; i < m; i++) {
		th[i][i] = t[i];
		for (j = i + 1; j < m; j++)th[i][j] = th[i][j - 1] * h + t[j];
		for (j = i - 1; j >= 0; j--)th[i][j] = th[i][j + 1] * h + t[j];
	}
	int at=-1,nx=-1;
	pair<int, int> pos;
	bool q;
	while (at != m - 1) {
		for (i = 1; at + i < m; i++) {
			q = 0;
			for (j = 0; j + i - 1 < n; j++) {
				if (sh[j][j + i - 1] == th[at + 1][at + i])q = 1, pos = { j,j + i - 1 };
				if (sh[j + i - 1][j] == th[at + 1][at + i])q = 1, pos = { j + i - 1,j };
			}
			if (q)nx = at + i;
			else break;
		}
		if (nx == at) { printf("-1"); return 0; }
		at = nx;
		v.push_back(pos);
	}
	printf("%d\n", v.size());
	for (auto p : v)printf("%d %d\n", p.first+1, p.second+1);
	getchar(); getchar();
}