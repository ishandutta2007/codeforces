#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

struct Node{
	int a, s[7];
}t[maxn];

inline bool cmp(Node x, Node y){
	return x.a > y.a;
}

int n, p, k;
ll f[maxn][128];

int main(){
	scanf("%d%d%d", &n, &p, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &t[i].a);
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < p;j++){
			scanf("%d", &t[i].s[j]);
		} 
	} 
	sort(t + 1, t + 1 + n, cmp);
	int sup = (1 << p) - 1;
	memset(f, -0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= sup;j++){
			for(int l = 0;l < p;l++){
				if(j & (1 << l)){
					f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << l)] + t[i].s[l]);
				}
			}
			int x = j, cnt = 0;
			while(x){
				if(x & 1) ++cnt;
				x >>= 1;
			}
			f[i][j] = max(f[i][j], f[i - 1][j] + (i - cnt <= k ? t[i].a : 0));//debug: a 
			//printf("%d %d %lld--\n", i, j, f[i][j]);
		}
	}
	printf("%lld", f[n][sup]);
}