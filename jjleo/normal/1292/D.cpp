#include <bits/stdc++.h>
#define maxn 5086

using namespace std;

typedef long long ll; 

int n;
int a[maxn], b[maxn];
int p[maxn], cnt;
bool tag[maxn];
int x;
int f[maxn][maxn], num[maxn], g[maxn];
ll ans;//debug:n1e6 ll 

int main(){
	for(int i = 2;i <= 5000;i++){
		if(!tag[i]) p[++cnt] = i;
		for(int j = 1;j <= cnt && p[j] * i <= 5000;j++){
			tag[p[j] * i] = true;
			if(i % p[j] == 0) continue;
		}
	}
	for(int i = 2;i <= 5000;i++){
		x = i, memcpy(f[i], f[i - 1], sizeof(f[i - 1])), num[i] = num[i - 1], g[i] = g[i - 1];
		for(int j = 1;x != 1 && j <= cnt;j++){
			while(x % p[j] == 0) f[i][j]++, num[i]++, g[i] = max(g[i], j), x /= p[j];
		}
	}
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &x), ++a[x];
	for(int i = 1;i <= 5000;i++){
		ans += 1ll * a[i] * num[i];
		b[g[i]] += a[i];
		//printf("%d %d--\n", a[i], g[i]);
	}
	//printf("%d--\n", ans);
	while(1){
		bool suc = false;
		for(int i = 1;i <= cnt;i++){
			if(b[i] >= n - b[i]){
				//printf("%d %d--\n", p[i], b[i]);
				suc = true;
				ans -= b[i] - (n - b[i]);
				for(int j = 1;j <= 5000;j++){
					if(g[j]){
						if(g[j] == i){
							f[j][i]--;
							if(!f[j][i]){
								b[i] -= a[j];
								while(!f[j][g[j]] && g[j]) --g[j];
								if(g[j]) b[g[j]] += a[j];
							}
						}else{
							b[g[j]] -= a[j], g[j] = 0;//debug:b[g[j]]b[i] 
						}
					}
				}
				break;
			}
		}
		if(!suc) break;
	}
	printf("%lld", ans);
}