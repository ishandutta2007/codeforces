#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

int t, n;
int a[maxn];
int p[maxn], cnt;
long long f[maxn], g[maxn];

int main(){
	memset(a, 0x3f, sizeof(a));
	a[1] = 1;
	for(int i = 2;i < maxn;i++){
		if(!f[i]){
			f[i] = i + 1, g[i] = i + 1;
			a[f[i]] = min(a[f[i]], i);
			p[++cnt] = i;
		}
		for(int j = 1;p[j] * i < maxn && j <= cnt;j++){
			if(i % p[j]){
				f[p[j] * i] = f[i] * f[p[j]];
				g[p[j] * i] = p[j] + 1;
				if(f[p[j] * i] < maxn) a[f[p[j] * i]] = min(a[f[p[j] * i]], p[j] * i);
			}else{
				g[p[j] * i] = g[i] * p[j] + 1;
				f[p[j] * i] = f[i] / g[i] * g[p[j] * i];
				if(f[p[j] * i] < maxn) a[f[p[j] * i]] = min(a[f[p[j] * i]], p[j] * i);
				break;
			}
		}
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", a[n] == 0x3f3f3f3f ? -1 : a[n]);
	}
}