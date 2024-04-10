#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int k[maxn], l[2][maxn], r[2][maxn];
int f[2][maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d%d%d%d%d", &k[i], &l[0][i], &r[0][i], &l[1][i], &r[1][i]);
	}
	int nxt[2] = {n + 1, n + 1}, L[2] = {0, 0}, R[2] = {m, m};
	bool tag[2] = {true, true}, suc[2];
	for(int i = n;i;i--){
		for(int j = 0;j <= 1;j++){
			suc[j] = tag[j ^ 1] && max(L[j ^ 1], l[j][i]) <= k[i] && k[i] <= min(R[j ^ 1], r[j][i]);
			if(suc[j]) f[j][i] = nxt[j ^ 1];
		}
		for(int j = 0;j <= 1;j++){
			if(suc[j]){
				nxt[j] = i, L[j] = l[j ^ 1][i], R[j] = r[j ^ 1][i], tag[j] = true;
				continue;
			}
			if(!(l[j][i] <= k[i] && k[i] <= r[j][i])) tag[j] = false;
			L[j] = max(L[j], l[j ^ 1][i]), R[j] = min(R[j], r[j ^ 1][i]);
		}
	}
	for(int j = 0;j <= 1;j++){
		if(tag[j] && L[j] <= 0 && 0 <= R[j]){
			puts("Yes");
			int x = 1, y = nxt[j];
			while(x <= n){
				if(x > y){
					y = f[j][y], j ^= 1;
				}
				printf("%d ", j), x++;
			}
			return 0;
		}
	}
	puts("No");
}