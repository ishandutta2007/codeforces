#include <bits/stdc++.h>
#define maxn 2086

using namespace std;	

int n, p;
int a[maxn];
int x, y;
int ans[maxn], cnt;

int main(){
	scanf("%d%d", &n, &p);
	for(int i = 1;i <= n;i++) scanf("%d", &x), a[x]++;
	for(int i = 1;i < maxn;i++){
		x = y = 0;
		for(int j = 1;j <= n;j++){
			while(x + 1 <= i + j - 1 && x < maxn - 1) x++, y += a[x];
			if(y % p == 0) break;
			//printf("%d %d %d--\n", i, j, y);
			y--;
			if(j == n) ans[++cnt] = i;
		}
	}
	printf("%d\n", cnt);
	for(int i = 1;i <= cnt;i++) printf("%d ", ans[i]);
	
}