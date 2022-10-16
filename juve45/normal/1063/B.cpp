#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

int d[] = {1, -1};

const int N = 2018;
int n, k, m, x, y, use[N][N], dmin[N][N], dl , dr;
string s[N];

bool ok(int x, int y) {
	if(x < 0 || y < 0)
		return 0;
	if(x >= n || y >= m)
		return 0;
	if(use[x][y] || s[x][y] == '*')
		return 0;
	return 1;
}

priority_queue <pair<int, pair<int, int> > > q;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> x >> y;
	cin >> dl >> dr;

	for(int i = 0; i < n; i++)
		cin >> s[i];

	x--, y--;
	memset(dmin, 0, sizeof dmin); 

	q.push({0, {x, y}});
	use[x][y] = 1;

	while(!q.empty()) {
		auto p = q.top().nd;
		q.pop();

		for(int i = 0; i < 2; i++) {
			if(ok(p.st + d[i], p.nd)) {
				use[p.st + d[i]][p.nd] = 1;
				q.push({-dmin[p.st][p.nd], {p.st + d[i], p.nd}});
				dmin[p.st + d[i]][p.nd] = dmin[p.st][p.nd];
			}
		}

		for(int i = 0; i < 2; i++) {
			if(ok(p.st, p.nd + d[i])) {
				use[p.st][p.nd + d[i]] = 1;
				q.push({-dmin[p.st][p.nd] - 1, {p.st, p.nd + d[i]}});
				dmin[p.st][p.nd + d[i]] = dmin[p.st][p.nd] + 1;
			}
		}
	}

	// dbg_v(dmin[0], m + 1);
	// dbg_v(dmin[1], m + 1);
	// dbg_v(dmin[2], m + 1);
	// dbg_v(dmin[3], m + 1);
	int l, r, ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(use[i][j] == 1 && s[i][j] == '.') {
				if(j < y) {
					r = (dmin[i][j] - (y - j)) / 2;
					l = r + (y - j);
				} else {
					l = (dmin[i][j] - (j - y)) / 2;
					r = l + (j - y);
				}
				// dbg(i);
				// dbg(j);
				// dbg(l);
				// dbg(r);
				ans += (l <= dl && r <= dr);
			}
	cout << ans << '\n';

}