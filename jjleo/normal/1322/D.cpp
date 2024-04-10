#include <bits/stdc++.h>
#define maxn 5005

using namespace std;

struct Node{
	int l, s;
}a[maxn];

inline bool cmp(Node x, Node y){
	return x.l < y.l;
}

int n, m;
int c[maxn];
int f[maxn][maxn];
int t[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = n;i;i--) scanf("%d", &a[i].l);
	for(int i = n;i;i--) scanf("%d", &a[i].s);
	for(int i = 1;i <= n + m;i++) scanf("%d", &c[i]);
	//sort(a + 1, a + 1 + n, cmp);
	//memset(f, -0x3f, sizeof(f));
	//for(int i = 1;i <= n + m;i++) f[i][0] = 0;
	for(int i = 0;i <= n + m;i++) for(int j = 1;j <= n;j++) f[i][j] = -0x3f3f3f3f;
	t[0] = n;
	for(int i = 1;i <= n;i++) t[i] = t[i - 1] >> 1; 
	for(int i = 1;i <= n;i++){
		for(int j = n;j;j--) f[a[i].l][j] = max(f[a[i].l][j], f[a[i].l][j - 1] + c[a[i].l] - a[i].s);
		/*for(int j = a[i].l;j <= n + m;j++){
			for(int l = 0;l <= n;l++) f[j + 1][l >> 1] = max(f[j + 1][l >> 1], f[j][l] + (l >> 1) * c[j + 1]);
		}*/
		/*for(int j = a[i].l, k = n;j <= n + m;j++, k >>= 1){
			for(int l = 0;l <= k;l++){
				f[j + 1][l >> 1] = max(f[j + 1][l >> 1], f[j][l] + (l >> 1) * c[j + 1]);
			}
		}*/
		for(int j = a[i].l;j <= n + m;j++){
			for(int k = 0;k <= t[j - a[i].l];k++){
				f[j + 1][k >> 1] = max(f[j + 1][k >> 1], f[j][k] + (k >> 1) * c[j + 1]);
			}
		}
	}
	printf("%d", f[n + m][0]);
}