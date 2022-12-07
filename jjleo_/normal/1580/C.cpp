#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m;
const int sn = 450;
int a[455][455], b[maxn];
int x[maxn], y[maxn], last[maxn];
int opt, k;
int ans;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 1;i <= m;i++){
		scanf("%d%d", &opt, &k);
		if(opt == 1){
			last[k] = i;
			if(x[k] + y[k] > sn){
				int now = i;
				while(1){
					now += x[k];
					if(now > m) break;
					b[now]++;
					now += y[k];
					if(now > m) break;
					b[now]--;
				}
			}else{
				int p = x[k] + y[k];
				a[p][(i + x[k]) % p]++, a[p][i % p]--;
				ans++;
			}
		}else{
			if(x[k] + y[k] > sn){
				int now = last[k];
				while(1){
					now += x[k];
					if(now > m) break;
					b[now]--;
					now += y[k];
					if(now >= i && now - y[k] < i) ans--;
					if(now > m) break;
					b[now]++;
				}
			}else{
				int p = x[k] + y[k];
				a[p][(last[k] + x[k]) % p]--, a[p][last[k] % p]++;
				int dis1 = ((last[k] - i) % p + p) % p, dis2 = ((last[k] + x[k] - i) % p + p) % p;
				if(dis1 < dis2) ans--;
			}	
		}
		ans += b[i];
		for(int j = 1;j <= sn;j++) ans += a[j][i % j];
		printf("%d\n", ans);
	}
}
/*
2 10000
1 1000000000
1 1
1 1
2 1
1 1
2 1
1 1
1 2
2 1
*/