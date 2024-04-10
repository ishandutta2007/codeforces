#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int ans[maxn];
int t, y;
long long x;
bool f[maxn], ff[maxn];
int g[maxn];

int main(){
	scanf("%d%d", &n, &m);
	f[0] = true;
	for(int i = 1;i <= n;i++){
		scanf("%d%lld%d", &t, &x, &y);
		if(t == 1){
			x = (x + 99999) / 100000;
			for(int j = 0;j < x;j++) g[j] = 0;
			for(int j = 0;j <= m;j++) ff[j] = 0;
			for(int j = 0;j <= m;j++){
				g[j % x] += f[j];
				if(j - (y + 1) * x >= 0) g[j % x] -= f[j - (y + 1) * x];
				ff[j] = g[j % x] != 0;
			}
			for(int j = 0;j <= m;j++){
				f[j] = ff[j];
				if(f[j] && !ans[j]) ans[j] = i;
			}
		}else{
			for(int j = 0;j <= m;j++) ff[j] = 0;
			for(int j = m;j;j--){
				if(!f[j]) continue;
				for(long long k = 1, l = (j * x + 99999) / 100000;k <= y && l <= m;k++, l = (l * x + 99999) / 100000){
					if(ff[l]) break;
					f[l] = true, ff[l] = true;
					if(!ans[l]) ans[l] = i;
				}
			}
		}
	}
	for(int i = 1;i <= m;i++) printf("%d ", ans[i] ? ans[i] : -1);
}