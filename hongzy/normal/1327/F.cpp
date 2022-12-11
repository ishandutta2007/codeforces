#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
 
const int N = 5e5 + 10;
const int mod = 998244353;	
int n, k, m;
struct Edge {
	int v, w, nxt;
} e[N];
int hd[N], ec;
void add(int u, int v, int w) {
	e[++ ec] = {v, w, hd[u]}; hd[u] = ec;
}
int solve(int k) {
	static int cov[N];
	for(int i = 0; i <= n; i ++) cov[i] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = hd[i]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if(w >> k & 1) {
				cov[v] ++; cov[i + 1] --;
			}
		}
	}
	for(int i = 1; i <= n; i ++) cov[i] += cov[i - 1]; 
	static int sum[N], f[N]; sum[0] = f[0] = 1; int le = 0;
	for(int i = 1; i <= n && cov[i]; i ++) {
		for(int j = hd[i]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if(!(w >> k & 1)) {
				return 0;
			}
		}
	}
	for(int i = 1; i <= n; i ++) if(!cov[i]) {
		int L = 0;
		for(int j = hd[i]; j; j = e[j].nxt) {
			int v = e[j].v, w = e[j].w;
			if(!(w >> k & 1)) {
				L = max(L, v);
			}
		}
		for(int u = i + 1; u <= n && cov[u]; u ++) {
			for(int j = hd[u]; j; j = e[j].nxt) {
				int v = e[j].v, w = e[j].w;
				if(!(w >> k & 1)) {
					if(v <= i) L = max(L, v);
					else return 0;
				}
			}
		}
		f[i] = sum[i - 1];
		if(le) (f[i] += mod - sum[le - 1]) %= mod;
		le = max(le, L);
		sum[i] = (sum[i - 1] + f[i]) % mod;
	} else f[i] = 0, sum[i] = sum[i - 1];
	int ans = sum[n];
	if(le) (ans += mod - sum[le - 1]) %= mod;
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i < m; i ++) {
		int l, r, w;
		scanf("%d%d%d", &l, &r, &w);
		add(r, l, w);
	}
	int ans = 1;
	for(int i = 0; i < k; i ++) {
		ans = 1ll * ans * solve(i) % mod;
		if(ans == 0) break ;
	}
	printf("%d\n", ans);
	return 0;
}