#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct pt {
	int x, y;
	pt operator+ (int z) {
		return {x + dx[z], y + dy[z]};
	}
	bool operator< (const pt& b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

void normalizuj(basic_string<pt>& a) {
	int x = 123123123;
	int y = 321321;
	for (auto p : a) {
		x = min(x, p.x);
		y = min(y, p.y);
	}

	for (auto& p : a) {
		p.x -= x;
		p.y -= y;
	}
}

basic_string<pt> generisi_90(int n) {
	basic_string<pt> a;
	for (int i=0; i<n; i++) {
		a += pt{0, i};
		a += pt{i, n};
		a += pt{n, n-i};
		a += pt{n-i, 0};
	}
	return a;
}

basic_string<pt> generisi_45(int n) {
	basic_string<pt> a;
	for (int i=0; i<n; i++) {
		a += pt{i, n+i};
		a += pt{n+i, 2*n-i};
		a += pt{2*n-i, n-i};
		a += pt{n-i, i};
	}
	return a;
}

bool is_sq(basic_string<pt> a) {
	if (a.empty() || a.size() % 4)
		return false;

	normalizuj(a);
	sort(a.begin(), a.end());
	int n = a.size() / 4;

	auto b = generisi_45(n);
	auto c = generisi_90(n);

	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	// for (auto p : a)
	// 	cerr << p.x << ' ' << p.y << '\n';
	// cerr << '\n';

	// for (auto p : b)
	// 	cerr << p.x << ' ' << p.y << '\n';
	// cerr << '\n';

	// for (auto p : c)
	// 	cerr << p.x << ' ' << p.y << '\n';
	// cerr << '\n';
	// cerr << '\n';

	return a == b || a == c;
}

/*
1111111...
1.....1...
1.11..1...
1.11..1.1.
1.....11.1
1..1..1.1.
1.1.1.1...
1..1..1...
1.....1...
1111111...
*/

void solve(vector<string> a, int n, int m) {
	int sol = 0;
	vector<basic_string<int>> vis(n, basic_string<int>(m, 0));

	auto ins = [&](pt p) {
		return 0 <= p.x && p.x < n && 0 <= p.y && p.y < m;
	};

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j] && a[i][j] == '1') {
				queue<pt> q;
				basic_string<pt> pts;
				q.push({i, j});
				pts += pt{i, j};
				vis[i][j] = 1;

				auto vs = [&](pt b) {
					if (!ins(b)) return;
					if (a[b.x][b.y] != '1') return;
					if (vis[b.x][b.y]) return;
					q.push(b);
					vis[b.x][b.y] = 1;
					pts += b;
				};

				while (q.size()) {
					auto f = q.front(); q.pop();
					for (int i=0; i<8; i++)
						vs(f+i);
				}

				if (is_sq(pts))
					sol++;
			}
		}
	}
	cout << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (string& s : a)
			cin >> s;
		solve(a, n, m);
	}
}