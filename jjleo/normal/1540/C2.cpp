#include <bits/stdc++.h>
#define maxn 105
#define maxN 10086

using namespace std;

const int p = 1e9 + 7;

int n, q, x;
int b[maxn], c[maxn], f[maxN], g[maxN], sb[maxn];

int cal(int x){
	for(int i = 0;i < maxN;i++) g[i] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < maxN;j++) f[j] = 0;
		for(int j = max(0, i * x + sb[i]);j < maxN;j++) f[j] = (g[j] + p - (j - c[i] - 1 >= 0 ? g[j - c[i] - 1] : 0)) % p;
		for(int j = 0;j < maxN;j++) g[j] = (f[j] + (j ? g[j - 1] : 0)) % p, f[j] = 0;
	}
	return g[maxN - 1];
}

map<int, int> mp;

int main(){
	scanf("%d", &n);
	int sum = 1;
	for(int i = 1;i <= n;i++) scanf("%d", &c[i]), sum = 1ll * sum * (c[i] + 1) % p;
	for(int i = 1;i < n;i++) scanf("%d", &b[i]);
	for(int i = 2;i <= n;i++) for(int j = 1;j < i;j++) sb[i] += (i - j) * b[j];
	int l = -((sb[n] + n - 1) / n), r = (n * maxn - sb[n] + n - 1) / n;
	for(int i = l;i <= r;i++) mp[i] = cal(i);
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		if(x < l) printf("%d\n", sum);
		else if(x > r) puts("0");
		else printf("%d\n", mp[x]);
	}
}