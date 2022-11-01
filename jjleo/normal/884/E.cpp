#include <bits/stdc++.h>
#define maxn 20086
using namespace std;

int n, m;

struct dsu{
	int fa[maxn];;
	bool tag[maxn];
	
	int find(int x){
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	
	inline void unionSet(int x, int y){
		x = find(x), y = find(y);
		if(x == y) return;
		fa[x] = y;
	}
}d[2];

int a[2][maxn];
char s[maxn];
int ans;

int main(){
	scanf("%d%d", &n, &m);
	int x = 0;
	for(int j = 1;j <= m;j++){
		d[x].fa[j] = j, d[x].tag[j] = false;
		d[x ^ 1].fa[j] = j, d[x ^ 1].tag[j] = false;
	}
	for(int i = 1;i <= n;i++, x ^= 1){
		scanf("%s", s + 1);
		for(int j = 1, k = 1;j <= m;k++){
			int y;
			if(s[k] >= '0' && s[k] <= '9') y = s[k] - '0';
			else y = 10 + s[k] - 'A';
			for(int z = 1 << 3;z;z >>= 1, j++){
				a[x][j] = (y & z) > 0;
			}
		}
		//for(int j = 1;j <= m;j++) printf("%d", a[x][j]);puts("");
		for(int j = 1;j <= m;j++){
			if(!a[x][j]) continue;
			if(a[x][j - 1]) d[x].unionSet(j, j - 1);
			if(a[x ^ 1][j]){
				int fa = d[x ^ 1].find(j);
				if(!d[x ^ 1].tag[fa]){
					d[x ^ 1].fa[fa] = d[x ^ 1].fa[j] = j;
					d[x ^ 1].tag[j] = true;
				}else{
					d[x].unionSet(j, fa);
				}
			}
		}
		
		for(int j = 1;j <= m;j++){
			if(!a[x ^ 1][j]) continue;
			int fa = d[x ^ 1].find(j);
			if(!d[x ^ 1].tag[fa]) d[x ^ 1].tag[fa] = true, ans++;
		}
		for(int j = 1;j <= m;j++){
			d[x ^ 1].fa[j] = j, d[x ^ 1].tag[j] = false;
		}
	}
	for(int j = 1;j <= m;j++){
		if(!a[x ^ 1][j]) continue;
		int fa = d[x ^ 1].find(j);
		if(!d[x ^ 1].tag[fa]) d[x ^ 1].tag[fa] = true, ans++;
	}
	printf("%d", ans);
}