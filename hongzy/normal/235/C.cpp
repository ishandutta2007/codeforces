#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 2e6 + 10;
char str[N];
int id, la, nxt[N][26], len[N], slen[3], lnk[N], a[N], w[N];
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
	static int cnt[N]; int n = len[la];
	for(int i = 1; i <= id; i ++) cnt[len[i]] ++;
	for(int i = 1; i <= n; i ++) cnt[i] += cnt[i - 1];
	for(int i = 1; i <= id; i ++) a[cnt[len[i]] --] = i;
	for(int i = id; i >= 1; i --) {
		int u = a[i], f = lnk[u]; w[f] += w[u];
	}
}
bool vis[N];
int top, st[N];
int solve() {
	int u = 0, l = 0, ans = 0, stl = strlen(str);
	for(int i = 0; i < stl + stl; i ++) {
		int c = str[i < stl ? i : i - stl] - 'a';
		while(u && -1 == nxt[u][c]) {
			u = lnk[u]; l = len[u];
		}
		if(~ nxt[u][c]) {
			u = nxt[u][c]; l ++;
			if(l >= stl) {
				while(len[lnk[u]] >= stl) u = lnk[u];
				if(!vis[u]) {
					ans += w[u];
					st[++ top] = u;
					vis[u] = 1;
				}
			}
		}
	}
	while(top) vis[st[top --]] = 0;
	return ans;
}
int main() {
	scanf("%s", str); init();
	for(int i = 0; str[i]; i ++) extend(str[i] - 'a');
	tpo(); int t; scanf("%d", &t);
	while(t --) {
		scanf("%s", str);
		printf("%d\n", solve());
	}
	return 0;
}