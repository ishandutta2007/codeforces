#include <bits/stdc++.h>
using namespace std;
const int N = 2 * (9e5 + 5);
const int mo = 1e9 + 7;
char str[N];
int id, n, la, nxt[N][27], len[N], slen[3], lnk[N], a[N], w[N][3];
void clr(int x) { fill(nxt[x], nxt[x] + 27, -1); }
void init() {
	id = la = len[0] = 0; lnk[0] = -1; clr(0);
}
void extend(int c, int cur) {
	int u = ++ id, p = la;
	len[u] = len[la] + 1; clr(u);
	for(; ~ p && -1 == nxt[p][c]; p = lnk[p]) {
		nxt[p][c] = u;
	}
	if(p == -1) lnk[u] = 0;
	else {
		int q = nxt[p][c];
		if(len[p] + 1 == len[q]) {
			lnk[u] = q;
		} else {
			int q0 = ++ id;
			copy(nxt[q], nxt[q] + 27, nxt[q0]);
			len[q0] = len[p] + 1; lnk[q0] = lnk[q];
			lnk[q] = lnk[u] = q0;
			for(; ~ p && nxt[p][c] == q; p = lnk[p]) {
				nxt[p][c] = q0;
			}
		}
	}
	la = u;
	if(~ cur) w[u][cur] = 1, slen[cur] ++;
}
int dt[N];
void tpo() {
	static int cnt[N];
	int n = len[la];
	for(int i = 1; i <= id; i ++) cnt[len[i]] ++;
	for(int i = 1; i <= n; i ++) cnt[i] += cnt[i - 1];
	for(int i = 1; i <= id; i ++) a[cnt[len[i]] --] = i;
	for(int i = id; i >= 1; i --) {
		int u = a[i], f = lnk[u];
		for(int j = 0; j < 3; j ++) w[f][j] += w[u][j];
		int tot = 1ll * w[u][0] * w[u][1] % mo * w[u][2] % mo;
		if(tot == 0) continue ;
		(dt[len[f] + 1] += tot) %= mo;
		((dt[len[u] + 1] -= tot) += mo) %= mo;
	}
	int m = min(slen[0], min(slen[1], slen[2]));
	for(int i = 1; i <= m; i ++) {
		(dt[i] += dt[i - 1]) %= mo;
		printf("%d%c", dt[i], " \n"[i == m]);
	}
}
int main() {
	scanf("%s", str); init();
	for(int i = 0; str[i]; i ++) extend(str[i] - 'a', 0);
	scanf("%s", str); extend(26, -1);
	for(int i = 0; str[i]; i ++) extend(str[i] - 'a', 1);
	scanf("%s", str); extend(26, -1);
	for(int i = 0; str[i]; i ++) extend(str[i] - 'a', 2);
	tpo();
	return 0;
}