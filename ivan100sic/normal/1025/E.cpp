#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;

	pt& operator+= (const pt& o) {
		x += o.x;
		y += o.y;
		return *this;
	}

	pt operator+ (const pt& o) const {
		auto t = *this;
		t += o;
		return t;
	}

	bool operator!= (const pt& o) const {
		return x != o.x || y != o.y;
	}
};

struct pot {
	pt u, v;
};

int n, m;

struct objekat {
	int blok[55][55];
	pt a[55];
	vector<pot> sol;
	int tag;
} igrice[2];

void pomeri(pt p, pt q, objekat& obj) {
	obj.sol.push_back({p, q});
	int i = obj.blok[p.x][p.y];

	obj.a[i] = q;
	obj.blok[p.x][p.y] = 0;
	obj.blok[q.x][q.y] = i;
}

pt pred[55][55];
pt dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool unutra(pt p) {
	return p.x > 0 && p.x <= n && p.y > 0 && p.y <= n;
}

void odsetaj(pt p, pt q, objekat& obj) {
	// bfs
	queue<pt> qu;
	qu.push(p);
	memset(pred, 255, sizeof(pred));

	while (!qu.empty()) {
		pt u = qu.front(); qu.pop();

		for (auto v : dir) {
			auto w = u + v;
			if (unutra(w) && obj.blok[w.x][w.y] == 0 && pred[w.x][w.y].x == -1) {
				pred[w.x][w.y] = u;
				qu.push(w);
			}
		}
	}

	vector<pt> trail = {q};
	pt tmp = q;
	while (pred[tmp.x][tmp.y].x != -1) {
		tmp = pred[tmp.x][tmp.y];
		trail.push_back(tmp);
	}

	for (int i=(int)trail.size()-2; i>=0; i--)
		pomeri(trail[i+1], trail[i], obj);
}

int dist[55][55];

void distonlybfs(pt p, objekat& obj) {
	// bfs
	queue<pt> qu;
	qu.push(p);
	memset(dist, 63, sizeof(dist));
	memset(pred, 255, sizeof(pred));

	dist[p.x][p.y] = 0;

	while (!qu.empty()) {
		pt u = qu.front(); qu.pop();

		for (auto v : dir) {
			auto w = u + v;
			if (unutra(w) && obj.blok[w.x][w.y] == 0 && pred[w.x][w.y].x == -1) {
				pred[w.x][w.y] = u;
				dist[w.x][w.y] = dist[u.x][u.y] + 1;
				qu.push(w);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		igrice[0].blok[x][y] = i;
		igrice[0].a[i] = {x, y};
	}
	igrice[0].tag = 0;

	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		igrice[1].a[i] = {x, y};
		igrice[1].blok[x][y] = i;
	}
	igrice[1].tag = 1;

	for (objekat& obj : igrice) {
		// poredjaj ih na dijagonalu u nekom redosledu
		bool nestosedesava = true;
		while (nestosedesava) {
			nestosedesava = false;
			for (int i=1; i<=n; i++)
				for (int j=1; j<=n; j++)
					if (i != j && obj.blok[i][j]) {
						int k = obj.blok[i][j];
						distonlybfs(obj.a[k], obj);

						int lele = -1;
						for (int l=1; l<=n; l++)
							if (dist[l][l] == abs(i-l) + abs(j-l)) {
								lele = l;
								break;
							}

						if (lele != -1) {

							odsetaj(obj.a[k], pt{lele, lele}, obj);
							nestosedesava = true;
						}
					}
		}

		// sabij ih O(n) poteza
		int c = 0;
		for (int i=1; i<=n; i++) {
			if (obj.blok[i][i]) {
				c++;
				if (i != c)
					odsetaj(obj.a[obj.blok[i][i]], {c, c}, obj);
			}
		}

		// ispravno ih poredjaj na dijagonalu

		if (obj.tag == 1) {
			for (int i=1; i<=m; i++) {
				int u = igrice[0].blok[i][i]; // ko treba da bude na poziciji i
				int v = obj.blok[i][i]; // ko je stvarno tamo

				if (u != v) {
					int i1 = obj.a[v].x;
					int j1 = obj.a[u].x;

					int steps = j1 - i1;

					for (int rep=0; rep<steps; rep++) {
						pomeri(obj.a[v], obj.a[v] + pt{0, 1}, obj);
						pomeri(obj.a[u], obj.a[u] + pt{0, -1}, obj);
					}

					for (int rep=0; rep<steps; rep++) {
						pomeri(obj.a[v], obj.a[v] + pt{1, 0}, obj);
						pomeri(obj.a[u], obj.a[u] + pt{-1, 0}, obj);
					}
				}
			}
		}
	}

	reverse(igrice[1].sol.begin(), igrice[1].sol.end());
	for (auto& g : igrice[1].sol)
		igrice[0].sol.push_back({g.v, g.u});

	cout << igrice[0].sol.size() << '\n';
	for (auto p : igrice[0].sol)
		cout << p.u.x << ' ' << p.u.y << ' ' << p.v.x << ' ' << p.v.y << '\n';
}