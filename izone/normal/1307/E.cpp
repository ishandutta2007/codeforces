/* 2020. 02. 17. IZ*ONE - Fiesta */

#include<cstdio>
#include<algorithm>
#include<vector>
#define SZ 262144
#define pil pair<int, long long>
using namespace std;

int n, m, w[5010];
long long Mod = 1000000007;
struct point {
	int a, c, l, r;
}P[5010];

int C[5010][4];

pil Get(int l, int r) {
	int i;
	for (i = 1; i <= n; i++)C[i][0] = 1, C[i][1] = C[i][2] = C[i][3] = 0;
	for (i = 1; i <= m; i++) {
		int x = P[i].a;
		int t1 = C[x][1], t2 = C[x][2];
		if (P[i].l <= l) {
			C[x][1] = C[x][1] + 1;
			C[x][3] = C[x][3] + t2;
		}
		if (P[i].r >= r) {
			C[x][2] = C[x][2] + 1;
			C[x][3] = C[x][3] + t1;
		}
	}
	int c = 0;
	long long rr = 1;
	for (i = 1; i <= n; i++) {
		if (C[i][3]) {
			c += 2;
			rr = rr * C[i][3] % Mod;
		}
		else if (C[i][1] + C[i][2]) {
			c++;
			rr = rr * (C[i][1] + C[i][2]) % Mod;
		}
	}
	return { c,rr };
}

int main() {
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (i = 1; i <= m; i++) {
		scanf("%d%d", &P[i].a, &P[i].c);
		int c = 0;
		for (j = 1; j <= n; j++) {
			if (w[j] == P[i].a)c++;
			if (c == P[i].c)break;
		}
		P[i].l = j;
		c = 0;
		for (j = n; j >= 1; j--) {
			if (w[j] == P[i].a)c++;
			if (c == P[i].c)break;
		}
		P[i].r = j;
	}
	int r1 = 0;
	long long r2 = 0;
	for (i = 0; i <= n; i++) {
		pil t = Get(i, i + 1);
		if (i != 0) {
			pil t2 = Get(i - 1, i + 1);
			if (t.first == t2.first) {
				t.second = (t.second - t2.second + Mod) % Mod;
			}
		}
		if (r1 < t.first) {
			r1 = t.first;
			r2 = 0;
		}
		if (r1 == t.first)r2 = (r2 + t.second) % Mod;
	}
	printf("%d %lld\n", r1, r2);
}