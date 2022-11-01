#include <bits/stdc++.h>
#define maxn 10000086

using namespace std;

int n;
int p[maxn], f[maxn], cnt;
int ans[maxn][2];
int x;

int main(){
	scanf("%d", &n);
	for(int i = 2;i < maxn;i++){
		if(!f[i]) p[++cnt] = i, f[i] = i;
		for(int j = 1;j <= cnt && p[j] * i < maxn;j++){
			f[p[j] * i] = p[j];
			if(i % p[j] == 0) break;
		}
	}
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		ans[i][0] = 1;
		int y = f[x];
		while(x % y == 0) x /= y, ans[i][0] *= y;
		if(x == 1) ans[i][0] = ans[i][1] = -1;
		else ans[i][1] = x;
	}
	for(int i = 1;i <= n;i++) printf("%d ", ans[i][0]);puts("");
	for(int i = 1;i <= n;i++) printf("%d ", ans[i][1]);
}