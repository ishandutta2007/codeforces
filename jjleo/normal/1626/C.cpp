#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
int k[maxn], h[maxn];

ll f[maxn], g[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &k[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &h[i]);
		for(int i = 1;i <= n;i++){
			f[i] = g[i] = 1e18;
			for(int j = i - 1;~j;j--){
				if(k[i] - k[j] >= h[i]){
					f[i] = g[j] + 1ll * h[i] * (h[i] + 1) / 2;
					break; 
				}else if(h[i] - (k[i] - k[j]) < h[j]) break;
			} 
			for(int x = 0;x <= i;x++){
				bool tag = false;
				for(int y = x + 1;y <= i;y++){
					if(h[x] + k[y] - k[x] < h[y]){
						tag = true;
						break;
					}
				}
				if(!tag){
					g[i] = min(g[i], f[x] + (1ll * h[x] + 1 + h[x] + k[i] - k[x]) * (k[i] - k[x]) / 2);
				}
			}
		}
		printf("%lld\n", g[n]);
	} 
}