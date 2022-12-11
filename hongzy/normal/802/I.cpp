#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 10;
char str[N];
int id, n, la, nxt[N][26], len[N], lnk[N], a[N], w[N];
void clr(int x) { fill(nxt[x], nxt[x] + 26, -1); }
void init() { id = la = len[0] = 0; lnk[0] = -1; clr(0); }
void extend(int c) {
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
			copy(nxt[q], nxt[q] + 26, nxt[q0]);
			len[q0] = len[p] + 1; lnk[q0] = lnk[q];
			lnk[q] = lnk[u] = q0;
			for(; ~ p && nxt[p][c] == q; p = lnk[p]) {
				nxt[p][c] = q0;
			}
		}
	}
	la = u; w[u] = 1;
}
void tpo() {
	static int cnt[N];
	int n = len[la];
	fill(cnt + 1, cnt + n + 1, 0);
	for(int i = 1; i <= id; i ++) cnt[len[i]] ++;
	for(int i = 1; i <= n; i ++) cnt[i] += cnt[i - 1];
	for(int i = 1; i <= id; i ++) a[cnt[len[i]] --] = i;
}
int main() {
	// freopen("input", "r", stdin);
	int test; scanf("%d", &test);
	while(test --) {
		scanf("%s", str); init();
		for(int i = 0; str[i]; i ++) extend(str[i] - 'a');
		tpo();
		long long ans = 0;
		for(int i = id; i >= 1; i --) {
			int u = a[i], f = lnk[u]; w[f] += w[u];
			ans += 1ll * (len[u] - len[f]) * w[u] * w[u]; w[u] = 0; 
		}
		printf("%lld\n", ans);
	}
	return 0;
}