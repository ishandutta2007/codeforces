#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int x[maxn], y[maxn];
bool vis[maxn];

long long dis(int i, int j){
	return 1ll * (x[i] - x[j]) * (x[i] - x[j]) + 1ll * (y[i] - y[j]) * (y[i] - y[j]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d%d", &x[i], &y[i]);
	int x = 1;
	vis[1] = true;
	printf("1 ");
	for(int i = 2;i <= n;i++){
		int y = 0; 
		for(int j = 1;j <= n;j++){
			if(x == j || vis[j]) continue;
			if(!y || dis(x, j) > dis(x, y)) y = j;
		}
		printf("%d ", y);
		vis[x = y] = true;
	}
}