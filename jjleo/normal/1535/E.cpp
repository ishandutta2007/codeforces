#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int q;
int a[maxn], c[maxn];
int opt;
int x, y, z;
int fa[maxn][25];
int dep[maxn];

int main(){
	scanf("%d%d%d", &q, &a[1], &c[1]);
	for(int i = 2;i <= q + 1;i++){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d%d", &x, &y, &z);
			a[i] = y, c[i] = z;
			fa[i][0] = ++x, dep[i] = dep[x] + 1;
			for(int j = 1;j <= 20;j++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}else{
			scanf("%d%d", &x, &y);
			x++;
			int cnt = 0;
			ll ans = 0;
			if(a[x]){
				int u = x;
				for(int j = 20;~j;j--) if(a[fa[u][j]]) u = fa[u][j];
				while(1){
					if(!y) break;
					int mn = min(y, a[u]);
					y -= mn, a[u] -= mn;
					cnt += mn, ans += 1ll * mn * c[u];
					if(u == x) break;
					int sum = dep[x] - dep[u] - 1;
					u = x;
					for(int j = 0;j <= 20;j++) if(sum & (1 << j)) u = fa[u][j];
				}
			}
			printf("%d %lld\n", cnt, ans);
			fflush(stdout);
		}
	}
}