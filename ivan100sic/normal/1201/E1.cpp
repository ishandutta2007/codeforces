#include <bits/stdc++.h>
#define CHECK if (xb == xw && yb == yw) return 0;
#define JED jed(xw, yw, xb, yb)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int db[1005][1005], dw[1005][1005];
pair<int, int> pb[1005][1005], pw[1005][1005];

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

template<class T, class U>
void bfs(int x0, int y0, T d, U p) {
	vector<pair<int, int>> q = {{x0, y0}};
	size_t qs = 0;
	memset(d, 63, sizeof(db));
	d[x0][y0] = 0;
	p[x0][y0] = {-1, -1};
	while (qs != q.size()) {
		auto [x, y] = q[qs++];
		for (int dir=0; dir<8; dir++) {
			int xx = x + dx[dir];
			int yy = y + dy[dir];
			if (xx < 1 || xx > n || yy < 1 || yy > m)
				continue;
			if (d[xx][yy] > 1231231) {
				d[xx][yy] = d[x][y] + 1;
				p[xx][yy] = {x, y};
				q.emplace_back(xx, yy);
			}
		}
	}
}

pair<int, int> gmv() {
	int x, y;
	cin >> x >> y;
	if (x == -1 || y == -1)
		exit(1); // :(
	return {x, y};
}

void pmv(int x, int y) {
	cout << x << ' ' << y << '\n' << flush;
}

bool jed(int x, int y, int ax, int ay) {
	x = abs(x-ax);
	y = abs(y-ay);
	return x*y == 2 && x+y == 3;
}

void player(string s) {
	cout << s << '\n' << flush;
}

template<class T>
void dbg(T dw) {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cerr << dw[i][j] << " \n"[j == m];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	int xw, yw, xb, yb;
	cin >> xw >> yw >> xb >> yb;

	// sta da radim?
	int txw = n/2  , tyw = m/2;
	int txb = n/2+1, tyb = m/2;

	bfs(txw, tyw, dw, pw);
	bfs(txb, tyb, db, pb);

	// prvi slucaj, parna udaljenost, crni jede belog
	if ((xw+yw+xb+yb) % 2 == 0) {
		// ako crni moze da dodje pre belog do belog cilja
		// ili jednako vreme
		// onda pobedjuje, samo odi tamo i onda se prosetaj do crnog cilja
		if (dw[xw][yw] >= dw[xb][yb]) {
			player("BLACK");
			// cepaj do cilja
			while (dw[xb][yb] > 0) {
				tie(xw, yw) = gmv();
				tie(xb, yb) = pw[xb][yb];
				pmv(xb, yb);
				CHECK;
			}

			// pomeri se negde. Ako se on prvo priblizi na
			// jedan potez od cilja onda ga lepo pojedi instead
			{
				tie(xw, yw) = gmv();
				if (JED) {
					pmv(xw, yw);
					return 0;
				} else {
					xb += 1, yb += 2;
					pmv(xb, yb);
				}
			}

			// sad sam na dva poteza od cilja, on na bar 3
			{
				tie(xw, yw) = gmv();
				if (JED) {
					pmv(xw, yw);
					return 0;
				} else {
					xb += 2, yb -= 1;
					pmv(xb, yb);
				}
			}

			// sad sam na jedan potez od cilja
			{
				tie(xw, yw) = gmv();
				if (JED) {
					pmv(xw, yw);
					return 0;
				} else {
					xb -= 2, yb -= 1;
					pmv(xb, yb);
					return 0;
				}
			}
		}

		// ako crni moze da dodje do crnog cilja pre nego
		// sto beli dodje do belog cilja onda crni pobedjuje, samo ide na cilj
		if (db[xb][yb] < dw[xw][yw]) {
			player("BLACK");
			// cepaj do cilja
			while (db[xb][yb] > 0) {
				tie(xw, yw) = gmv();
				tie(xb, yb) = pb[xb][yb];
				pmv(xb, yb);
				CHECK;
			}
			return 0;
		}

		// inace igraj sa belim, uteraj ga u cilj
		{
			player("WHITE");
			// cepaj do cilja
			while (dw[xw][yw] > 0) {
				tie(xw, yw) = pw[xw][yw];
				pmv(xw, yw);
				tie(xb, yb) = gmv();
			}
			return 0;
		}

	}

	else
	// drugi slucaj, beli jede crnog. Gledacemo da dodjemo do crnog
	// cilja pre ili jednako sa crnim pa da uradimo isto sto i gore
	{
		// beli moze do crnog cilja da stigne pre samog crnog
		// uradi tako!
		if (db[xw][yw]-1 <= db[xb][yb]) {
			player("WHITE");
			while (db[xw][yw] > 0) {
				tie(xw, yw) = pb[xw][yw];
				pmv(xw, yw);
				CHECK;
				tie(xb, yb) = gmv();
			}

			// skokni ka belom cilju
			{
				if (JED) {
					pmv(xb, yb);
					return 0;
				}
				xw += 2, yw += 1;
				pmv(xw, yw);
				tie(xb, yb) = gmv();
			}

			{
				if (JED) {
					pmv(xb, yb);
					return 0;
				}
				xw -= 2, yw += 1;
				pmv(xw, yw);
				tie(xb, yb) = gmv();
			}

			{
				if (JED) {
					pmv(xb, yb);
					return 0;
				}
				xw -= 1, yw -= 2;
				pmv(xw, yw);
				return 0;
			}
		}

		// ako beli moze da dodje do belog ili jednako
		// sa crnim da dodje do crnog, do it
		if (dw[xw][yw] <= db[xb][yb]) {
			player("WHITE");
			// cepaj do cilja
			while (dw[xw][yw] > 0) {
				tie(xw, yw) = pw[xw][yw];
				pmv(xw, yw);
				CHECK;
				tie(xb, yb) = gmv();
			}
			return 0;
		}

		// inace jbg igraj sa crnim, no check
		{
			player("BLACK");
			while (db[xb][yb] > 0) {
				tie(xw, yw) = gmv();
				tie(xb, yb) = pb[xb][yb];
				pmv(xb, yb);
			}
			return 0;
		}
	}
}