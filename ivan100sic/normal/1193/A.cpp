#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 18;
 
int n, m;
ll d0[1 << N];
ll d1[1 << N];
int u[1111], v[1111];
int a[N][N], b[N];
char se[1 << N][N];
char sf[1 << N][N];
bool ind[1 << N];

bool isind(int w) {
	for (int i=0; i<n; i++) if (w & (1 << i))
		if (b[i] & w)
			return false;
	return true;
}

void brut() {
	ll z = 0;
	for (int w=0; w<(1<<m); w++) {
		vector<vector<int>> e(n);
		vector<int> deg(n, 0), q;
		for (int i=0; i<m; i++) {
			if (w & (1 << i)) {
				e[u[i]].push_back(v[i]);
				deg[v[i]]++;
			} else {
				e[v[i]].push_back(u[i]);
				deg[u[i]]++;
			}
		}
		for (int i=0; i<n; i++)
			if (deg[i] == 0)
				q.push_back(i);
		size_t qs = 0;
		while (q.size() != qs) {
			int x = q[qs++];
			for (int y : e[x]) {
				if (!--deg[y]) {
					q.push_back(y);
				}
			}
		}
		if (n == (int)q.size())
			z += __builtin_popcount(w);
	}
	cout << z << '\n';
}
 
int main() {
	cin >> n >> m;
	 
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x][y] = 1;
		a[y][x] = 2;

		b[x] |= 1 << y;

		u[i] = x;
		v[i] = y;
	}

	if (m < 18) {
		brut();
		return 0;
	}
	 
	for (int w=0; w<(1<<n); w++) {
		ind[w] = isind(w);
		for (int i=0; i<n; i++)
			if (w & (1 << i)) {
				for (int j=0; j<n; j++)
					if (a[i][j] == 2)
						se[w][j]++;
					else if (a[i][j] == 1)
						sf[w][j]++;
			}
	}
	 
	d0[0] = 1;

	
	 
	for (int w=1; w<(1<<n); w++) {
		int k = 0, s = 0, sgn = -1, pc = 0;
		int bits[19];
		for (int i=0; i<n; i++)
			if (w & (1 << i))
				bits[pc++] = i;
		bits[pc] = 0; // samo da ne baguje
		for (int i=1; i<=(1<<pc); i++) {
			if (s && ind[s]) {
				d0[w] += d0[w-s] * sgn;
				d1[w] += (d0[w-s] * k + d1[w-s]) * sgn;
			}

			int j = bits[__builtin_ctz(i)];

			// cerr << w << ' ' << s << ' ' << k << ' ' << sgn << ' ' << j << '\n';

			if (s & (1 << j)) {
				k -= se[w-s][j];
				k += sf[s][j];
			} else {
				k += se[w-s][j];
				k -= sf[s][j];
			}
			s ^= 1 << j;
			sgn = -sgn;
		}

		d0[w] %= 998244353;
		d1[w] %= 998244353;
	}
	 
	cout << (d1[(1<<n)-1] + 998244353000000000) % 998244353 << '\n';
}