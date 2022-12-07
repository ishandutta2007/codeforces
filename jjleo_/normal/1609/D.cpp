#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, d;
int fa[maxn], siz[maxn];
int x, y;

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int a[maxn];

int main(){
	scanf("%d%d", &n, &d);
	for(int i = 1;i <= n;i++) fa[i] = i, siz[i] = 1;
	int cnt = 0;
	for(int i = 1;i <= d;i++){
		scanf("%d%d", &x, &y);
		x = find(x), y = find(y);
		if(x ^ y){
			if(siz[x] > siz[y]) swap(x, y);
			fa[x] = y, siz[y] += siz[x];
			cnt++;
		}
		int m = 0;
		for(int j = 1;j <= n;j++) if(find(j) == j) a[++m] = siz[j];
		sort(a + 1, a + 1 + m, greater<int>());
		int ans = 0;
		for(int j = 1;j <= i - cnt + 1;j++) ans += a[j];
		printf("%d\n", ans - 1);
	}
}