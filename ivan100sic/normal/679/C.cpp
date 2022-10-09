#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, bcc;
char a[505][505];
int cc[505][505];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int uc[130000];

void ch(int i, int j, int d) {
	if (cc[i][j])
		uc[cc[i][j]] += d;
}

void init(int x) {
	memset(uc, 0, sizeof uc);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (x <= i && i < x+k && j <= k)
				continue;
			ch(i, j, 1);
		}
	}
}

void mr(int x, int y) {
	for (int i=0; i<k; i++) {
		ch(x+i, y-1, 1);
		ch(x+i, y-1+k, -1);
	}
}

int nz[2005], ee;
bool seen[130000];

int getans(int x, int y) {
	ee = 0;
	for (int i=0; i<k; i++) {
		nz[ee++] = cc[x-1][y+i];
		nz[ee++] = cc[x+k][y+i];
		nz[ee++] = cc[x+i][y-1];
		nz[ee++] = cc[x+i][y+k];
	}

	int z = 0;
	for (int i=0; i<ee; i++) {
		if (!nz[i])
			continue;
		if (seen[nz[i]])
			continue;
		seen[nz[i]] = 1;
		z += uc[nz[i]];
	}
	
	for (int i=0; i<ee; i++)
		seen[nz[i]] = 0;

	return z+k*k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	memset(a, 'X', sizeof a);
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		copy(s.begin(), s.end(), a[i]+1);
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i][j] == '.' && cc[i][j] == 0) {
				vector<pair<int, int>> q = {{i, j}};
				cc[i][j] = ++bcc;
				size_t qs = 0;
				while (qs != q.size()) {
					auto [x, y] = q[qs++];
					for (int d=0; d<4; d++) {
						int xx = x + dx[d], yy = y + dy[d];
						if (a[xx][yy] == '.' && cc[xx][yy] == 0) {
							cc[xx][yy] = cc[x][y];
							q.emplace_back(xx, yy);
						}
					}
				}
			}
		}
	}

	int sol = 0;

	for (int i=1; i+k-1<=n; i++) {
		init(i);
		for (int j=1; j+k-1<=n; j++) {
			if (j > 1)
				mr(i, j);
			sol = max(sol, getans(i, j));
		}
	}

	cout << sol << '\n';
}