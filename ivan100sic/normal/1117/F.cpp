#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[17][17];
string s;
int nx[100005][17];
int cnt[17];
int ima[17][17][1 << 17];
int vis[1 << 17], moze[1 << 17];

void resi(int mask) {
	if (vis[mask])
		return;

	vis[mask] = 1;

	moze[mask] = 1;
	for (int i=0; i<m; i++) {
		if (!(mask & (1 << i)))
			continue;
		for (int j=0; j<m; j++) {

			if (!(mask & (1 << j)))
				continue;

			if (!a[i][j] && ima[i][j][(1 << m) - 1 - mask]) {
				moze[mask] = 0;
				return;
			}
		}
	}

	// cerr << "here! " << mask << '\n';

	for (int i=0; i<m; i++) {
		if (mask & (1 << i)) {
			resi(mask - (1 << i));
		}
	}
}

int wt(int mask) {
	int z = 0;
	for (int i=0; i<m; i++)
		if (mask & (1 << i))
			z += cnt[i];
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=0; i<m; i++)
		for (int j=0; j<m; j++)
			cin >> a[i][j];

	fill(nx[n], nx[n]+m, n);
	for (int i=n-1; i>=0; i--) {
		copy(nx[i+1], nx[i+1]+m, nx[i]);
		nx[i][s[i] - 'a'] = i;
	}

	for (int i=0; i<n; i++)
		cnt[s[i] - 'a']++;

	for (int i=0; i<n; i++) {
		// nadji niz
		int mask = 0;
		int x = i+1;
		while (x < n) {
			// nadji slovo koje je razlicito od svih iz maske
			int jj = -1;
			for (int j=0; j<m; j++) {
				if (mask & (1 << j))
					continue;
				if (jj == -1 || nx[x][j] < nx[x][jj])
					jj = j;
			}

			if (jj == -1 || nx[x][jj] == n) {
				// nema vise slova
				break;
			}

			int p = s[i] - 'a';
			int q = jj;
			ima[p][q][mask] |= 1;

			mask |= 1 << jj;
			x = nx[x][jj];
		}
	}

	// pusti sos
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			for (int dir=0; dir<m; dir++) {
				for (int mask=0; mask<(1<<m); mask++) {
					if (mask & (1 << dir)) {
						ima[i][j][mask] |= ima[i][j][mask - (1 << dir)];
					}
				}
			}
		}
	}

	// for (int k=0; k<8; k++)
	// 	cerr << ima[1][1][k];
	// cerr << '\n';

	// sad znam da li ce da se pojave susedni i,j ako probam neku masku
	resi((1 << m) - 1);

	int sol = n;

	for (int mask=0; mask<(1 << m); mask++) {
		if (moze[mask]) {
			sol = min(sol, wt(mask));
		}
	}

	cout << sol << '\n';
}