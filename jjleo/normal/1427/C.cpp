#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int r, n;
int t[maxn], x[maxn], y[maxn];
int f[maxn];
int ans;

int main(){
	scanf("%d%d", &r, &n);
	x[0] = y[0] = 1;
	memset(f, -0x3f, sizeof(f)), f[0] = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
		for(int j = max(0, i - 4 * r);j < i;j++){
			if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) f[i] = max(f[i], f[j] + 1);
		}
		ans = max(ans, f[i]);
	}
	printf("%d", ans);
}