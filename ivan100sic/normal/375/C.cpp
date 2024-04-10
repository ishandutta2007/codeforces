#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string a[20];
int iznad_m[20][20];
int is_bomb;
int vr[8];

int d[20][20][256];



struct state {
	int x, y, m;
	bool operator< (state b) const {
		if (x != b.x)
			return x < b.x;
		if (y != b.y)
			return y < b.y;
		return m < b.m;
	}
};

int& dd(state s) {
	return d[s.x][s.y][s.m];
}

bool land(char x) {
	return x == '.' || x == 'S';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	int t = 0;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (isdigit(a[i][j]))
				t++;

	for (int i=0; i<t; i++)
		cin >> vr[i];

	int x0 = -1, y0 = -1;

	{
		set<char> s;
		for (int i='1'; i<='8'; i++)
			s.insert(i);

		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (isdigit(a[i][j]))
					s.erase(a[i][j]);

		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				if (a[i][j] == 'B') {
					a[i][j] = *s.begin();
					s.erase(s.begin());
					is_bomb |= 1 << (a[i][j] - '1');
				}
	}
		
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) {
			if (a[i][j] == 'S')
				x0 = i, y0 = j;
			for (int k=0; k<i; k++)
				if (isdigit(a[k][j]))
					iznad_m[i][j] |= 1 << (a[k][j] - '1');
		}

	memset(d, 255, sizeof(d));
	queue<state> q;
	d[x0][y0][0] = 0;
	q.push({x0, y0, 0});
	while (q.size()) {
		auto u = q.front(); q.pop();
		int df = d[u.x][u.y][u.m];
		// gore
		if (u.x > 0 && land(a[u.x-1][u.y])) {
			auto v = u;
			v.x--;
			if (dd(v) == -1) {
				dd(v) = df + 1;
				q.push(v);
			}
		}
		// dole
		if (u.x+1 < n && land(a[u.x+1][u.y])) {
			auto v = u;
			v.x++;
			if (dd(v) == -1) {
				dd(v) = df + 1;
				q.push(v);
			}
		}
		// levo
		if (u.y > 0 && land(a[u.x][u.y-1])) {
			auto v = u;
			v.y--;
			v.m ^= iznad_m[v.x][v.y];
			if (dd(v) == -1) {
				dd(v) = df + 1;
				q.push(v);
			}
		}
		// desno
		if (u.y + 1 < m && land(a[u.x][u.y+1])) {
			auto v = u;
			v.m ^= iznad_m[v.x][v.y];
			v.y++;
			if (dd(v) == -1) {
				dd(v) = df + 1;
				q.push(v);
			}
		}
	}

	int sol = 0;
	for (int m=0; m<256; m++) {
		if ((m & is_bomb) == 0) {
			int z = 0;
			for (int j=0; j<t; j++)
				if (m & (1 << j))
					z += vr[j];
			if (d[x0][y0][m] == -1)
				continue;
			sol = max(sol, z - d[x0][y0][m]);
		}
	}
	cout << sol << '\n';
}