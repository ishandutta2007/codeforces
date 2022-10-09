#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct event {
	int x, y, c, dead;

	event() {
		dead = 2100003;
	}
};

int n, m, q;
event a[2100005];
basic_string<int> ec[2100005];
int lastt[305][305];
int col[305][305];
int buf[2100005];

pair<int, int> p[305][305];
bool w[305][305];

pair<int, int> ep(pair<int, int> u) {
	if (p[u.first][u.second] == u)
		return u;
	return p[u.first][u.second] = ep(p[u.first][u.second]);
}

bool spoji(pair<int, int> u, pair<int, int> v) {
	u = ep(u);
	v = ep(v);
	if (u == v)
		return false;
	p[u.first][u.second] = v;
	return true;
}

vector<pair<int, int>> dirty;

void init(int x, int y) {
	w[x][y] = 1;
	p[x][y] = {x, y};
	dirty.emplace_back(x, y);
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

void reset() {
	for (auto [x, y] : dirty)
		w[x][y] = 0;
	dirty = {};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(col, 255, sizeof col);

	cin >> n >> m >> q;
	for (int k=0; k<n*m; k++) {
		int i = k % n, j = k / n;
		i++, j++;
		a[k+1].x = i, a[k+1].y = j, a[k+1].c = 0;
	}

	for (int i=n*m+1; i<=n*m+q; i++) {
		cin >> a[i].x >> a[i].y >> a[i].c;
	}

	for (int i=1; i<=n*m+q; i++) {
		auto [x, y, c, we] = a[i];
		if (c == col[x][y]) {
			// preskacemo
			continue;
		}

		col[x][y] = c;
		a[lastt[x][y]].dead = i;
		lastt[x][y] = i;
		ec[c] += i;
	}

	// resi jedan po jedan
	for (int c=0; c<=2000000; c++) {
		if (ec[c].size() == 0)
			continue;
		reset();
		int bcc = 0;
		for (int br=0; br<(int)ec[c].size(); br++) {
			int j = ec[c][br];
			int jn = br == (int)ec[c].size()-1 ? j+1 : ec[c][br+1];

			int x = a[j].x, y = a[j].y;
			init(x, y); bcc++;
			for (int d=0; d<4; d++) {
				int xx = x + dx[d];
				int yy = y + dy[d];
				if (w[xx][yy]) {
					if (spoji({x, y}, {xx, yy})) {
						bcc--;
					}
				}
			}
			// cerr << "dodaj live " << j << ' ' << jn << ' ' << c << ' ' << bcc << '\n';
			buf[j] += bcc;
			buf[jn] -= bcc;
		}

		int mojzadnji = ec[c].back() + 1;

		vector<int> umiru;
		for (int j : ec[c])
			umiru.push_back(j);

		sort(umiru.begin(), umiru.end(), [](int j, int k) {
			return a[j].dead > a[k].dead;
		});

		reset();
		bcc = 0;

		for (int br=0; br<(int)umiru.size(); br++) {
			int j = umiru[br];
			int t1 = br == (int)umiru.size() - 1 ? mojzadnji : a[umiru[br+1]].dead;
			int t2 = a[j].dead;

			int x = a[j].x, y = a[j].y;
			init(x, y); bcc++;
			for (int d=0; d<4; d++) {
				int xx = x + dx[d];
				int yy = y + dy[d];
				if (w[xx][yy]) {
					if (spoji({x, y}, {xx, yy})) {
						bcc--;
					}
				}
			}

			// cerr << "dodaj dead " << t1 << ' ' << t2 << ' ' << c << ' ' << bcc << '[';
			// cerr << x << ", " << y << "]\n";

			buf[t1] += bcc;
			buf[t2] -= bcc;
		}
	}

	for (int i=1; i<=n*m+q; i++)
		buf[i] += buf[i-1];
	for (int i=n*m+1; i<=n*m+q; i++)
		cout << buf[i] << '\n';
}