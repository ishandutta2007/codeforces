#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5000 + 10;
int n, x, fa[N], ch[N][2], d[N], dt[N];
bool use[N];
int main() {
	int t; scanf("%d", &t);
	for(int T = 1; T <= t; T ++) {
		scanf("%d%d", &n, &x); dt[0] = -1;
		long long cur = n * (n - 1ll) / 2, dl = 0;
		for(int i = 1; i <= n; i ++) {
			fa[i] = d[i] = i - 1; dt[i] = dt[i >> 1] + 1; dl += dt[i];
			ch[i][0] = 0; ch[i][1] = i == n ? 0 : i + 1;
		}
		fill(use + 1, use + n + 1, 0);
		bool ok = 1;
		if(x > cur || x < dl) {
			ok = 0;
		} else {
			while(cur > x) {
//				printf("! %d\n", (int) cur);
				int u = -1;
				for(int i = 2; i <= n; i ++)
					if(!use[i] && !ch[i][0] && !ch[i][1]) {
						u = u == -1 ? i : (d[i] < d[u] ? i : u);
					}
				if(u == -1) { ok = 0; break ; }
				bool tag = 0;
				for(int i = 1; i <= n; i ++)
					if(d[i] == d[u] - 2 && (!ch[i][0] || !ch[i][1])) {
						ch[ fa[u] ][ ch[fa[u]][1] == u ] = 0;
						fa[u] = i; ch[i][ch[i][1] == 0] = u; d[u] --; cur --;
						tag = 1; break ;
					}
				if(!tag) use[u] = 1;
			} 
		}
		if(!ok) puts("NO");
		else {
			puts("YES");
			for(int i = 2; i <= n; i ++) printf("%d%c", fa[i], " \n"[i == n]);
		}
	}
	return 0;
}