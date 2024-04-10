#include <bits/stdc++.h>
using namespace std;
 
using i64 = long long;
const i64 P = 998244353;
#define maxN 2100

char g[maxN][maxN], gg[maxN][maxN];
int f[2 * maxN], n, m, sz[2 * maxN], sv[2 * maxN], v[2 * maxN], cntq[2 * maxN];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}

int main() {
	scanf("%d%d",&n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", g[i]);
	}
	if (n % 2 == 0 && m % 2 == 0) {
		i64 ans = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (g[i][j] =='?') ans = ans * 2 % P;
			}
		printf("%lld\n", ans);
		return 0;
	}
	if (n % 2 == 1 && m % 2 == 1) {
		for (int i = 0; i < n + m; i++) f[i] = i, v[i] = 0;
		i64 ans = 0, val = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '?') {
					cntq[i]++;
					cntq[j + n]++;
					if (find(i) == find(j + n)) val = val * 2 % P;
					else f[find(i)] = find(j + n);
				} else {
					v[i] ^= (g[i][j] - '0');
					v[j + n] ^= (g[i][j] - '0');
				}
			}
		}
		for (int B = 0; B <= 1; B++) {
			bool valid = 1;
			for (int i = 0; i < n + m; i++) {
				if (cntq[i] == 0 && v[i] != B) valid = 0;
			}
			for (int i = 0; i < n + m; i++) sz[i] = 0, sv[i]=0;
			for (int i = 0; i < n + m; i++) {
				sz[find(i)]++;
				sv[find(i)] ^= v[i];
			}
			for (int i = 0; i < n + m; i++) if (find(i) == i) {
				if (sv[i] != (sz[i] % 2) * B) { valid = 0; }
			}
			if (valid) ans = (ans + val) % P;
		}
		printf("%lld\n", ans);
		return 0;
	}
	if (n % 2 == 1) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				gg[j][i] = g[i][j];
		swap(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				g[i][j] = gg[i][j];
	}
	// n % 2 = 0 m % 2 = 1
	i64 ans = 0;
	for (int B = 0; B <= 1; B++) {
		i64 tmp = 1;
		for (int i = 0; i < n; i++) {
			int qm = 0, val = 0;
			for (int j = 0; j < m; j++) {
				if (g[i][j] == '?') qm++;
				else val ^= (g[i][j] - '0');
			}
			if (qm == 0 && val != B) tmp = 0;
			else {
				for (int j = 0; j < qm - 1; j++) tmp = tmp * 2 % P;
			}
		}
		ans = (ans + tmp) % P;
	}
	printf("%lld\n", ans);
}