#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

namespace SA {

const int N = 2e5 + 10;
int n, sa[N], rk[N], hei[N];
char s[N], ban[N];

void rd() {
	scanf("%d%s%s", &n, s + 1, ban + 1);
	reverse(s + 1, s + n + 1);
	reverse(ban + 1, ban + n + 1);
}

void build() {
	static int t[N], fir[N], sec[N], cnt[N];
	int i, c = 'z';
	for(i = 0; i <= c; i ++) cnt[i] = 0;
	for(i = 1; i <= n; i ++) cnt[s[i]] ++;
	for(i = 1; i <= c; i ++) cnt[i] += cnt[i - 1];
	for(i = 1; i <= n; i ++) sa[cnt[s[i]] --] = i;
	for(i = 1; i <= n; i ++) rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
	for(int k = 1; k <= n; k <<= 1) {
		c = rk[sa[n]];
		for(i = 1; i <= n; i ++) {
			fir[i] = rk[i]; sec[i] = i + k > n ? 0 : rk[i + k];
		}
		
		for(i = 0; i <= c; i ++) cnt[i] = 0;
		for(i = 1; i <= n; i ++) cnt[sec[i]] ++;
		for(i = 1; i <= c; i ++) cnt[i] += cnt[i - 1];
		for(i = 1; i <= n; i ++) t[cnt[sec[i]] --] = i;
		
		for(i = 0; i <= c; i ++) cnt[i] = 0;
		for(i = 1; i <= n; i ++) cnt[fir[t[i]]] ++;
		for(i = 1; i <= c; i ++) cnt[i] += cnt[i - 1];
		for(i = n; i >= 1; i --) sa[cnt[fir[t[i]]] --] = t[i];
		
		bool dif = 1; rk[sa[1]] = 1;
		for(i = 2; i <= n; i ++) {
			int v = sa[i - 1], u = sa[i]; rk[u] = rk[v] + 1;
			if(fir[v] == fir[u] && sec[v] == sec[u]) {
				rk[u] --; dif = 0;
			}
		}
		if(dif) break ;
	}
}

void height() {
	int k = 0;
	for(int i = 1; i <= n; i ++) {
		if(k) k --;
		int j = sa[rk[i] - 1];
		while(i + k <= n && j + k <= n && s[i + k] == s[j + k]) k ++;
		hei[rk[i]] = k;
	}
}


void solve() {
	static int st[N], pre[N], nxt[N], sum[N];
	int top = 0;
	st[++ top] = 1; hei[1] = -1;
	for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + (ban[sa[i]] == '0');
	for(int i = 2; i <= n; i ++) {
		while(hei[st[top]] >= hei[i]) top --;
		pre[i] = st[top]; st[++ top] = i;
	}
	st[top = 1] = n + 1; hei[n + 1] = -1;
	for(int i = n; i >= 2; i --) {
		while(hei[st[top]] > hei[i]) top --;
		nxt[i] = st[top]; st[++ top] = i;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i ++) if(ban[i] == '0') ans = max(ans, n - i + 1ll);
	for(int i = 2; i <= n; i ++)
		ans = max(ans, ( sum[nxt[i] - 1] - sum[pre[i] - 1] ) * 1ll * hei[i]);
	printf("%I64d\n", ans);
}

}

int main() {
	SA :: rd();
	SA :: build();
	SA :: height();
	SA :: solve();
	return 0;
}