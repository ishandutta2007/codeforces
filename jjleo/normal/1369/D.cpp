#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

const int p = 1e9 + 7;

int n, t;
int f[maxn];
int g[3];

int main(){
	f[3] = 1;
	for(int i = 4;i < maxn;i++) f[i] = (f[i - 1] + 1ll * f[i - 2] * 2) % p;
	for(int i = 1;i < maxn;i++){
		int x = f[i];
		f[i] = (f[i] + g[i % 3]) % p;
		g[i % 3] = (g[i % 3] + x) % p;
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", 1ll * f[n] * 4 % p);
	}
}