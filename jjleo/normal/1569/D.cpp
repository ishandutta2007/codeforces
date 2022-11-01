#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int t, n, m, k;
int x[maxn], y[maxn];
int xid[maxn], yid[maxn];
map<int, int> mpx[maxn], mpy[maxn];

int main(){
	scanf("%d", &t);
	memset(xid, -1, sizeof(xid)), memset(yid, -1, sizeof(yid));
	while(t--){
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &x[i]), xid[x[i]] = i;
		for(int i = 1;i <= m;i++) scanf("%d", &y[i]), yid[y[i]] = i;
		xid[0] = yid[0] = 0, xid[x[n + 1] = 1000000] = n + 1, yid[y[m + 1] = 1000000] = m + 1;
		while(k--){
			int a, b;
			scanf("%d%d", &a, &b);
			if(xid[a] != -1 && yid[b] != -1) continue;
			if(yid[b] == -1) mpy[upper_bound(y, y + m + 2, b) - y][xid[a]]++;
			else mpx[upper_bound(x, x + n + 2, a) - x][yid[b]]++;
		}
		long long ans = 0;
		for(int i = 0;i <= n + 1;i++){
			int sum = 0;
			for(map<int, int>::iterator it = mpx[i].begin();it != mpx[i].end();++it){
				sum += it->second;
				ans -= 1ll * (it->second) * (it->second - 1) / 2;
			}
			ans += 1ll * sum * (sum - 1) / 2;
		}
		for(int i = 0;i <= m + 1;i++){
			int sum = 0;
			for(map<int, int>::iterator it = mpy[i].begin();it != mpy[i].end();++it){
				sum += it->second;
				ans -= 1ll * (it->second) * (it->second - 1) / 2;
			}
			ans += 1ll * sum * (sum - 1) / 2;
		}
		printf("%lld\n", ans);
		for(int i = 0;i <= n + 1;i++) xid[x[i]] = -1, mpx[i].clear();
		for(int i = 0;i <= m + 1;i++) yid[y[i]] = -1, mpy[i].clear();
	}
}
/*
1
5 4 9
0 1 2 6 1000000
0 4 8 1000000
4 4
2 5
2 2
6 3
1000000 1
3 8
5 8
8 8
6 8
*/