#include <bits/stdc++.h>
#define maxn 505

using namespace std;

int t, n, m;
char s[maxn][maxn];
int dx[4] = {1, 1, -1, -1}, dy[4] = {1, -1, 1, -1}; 

int get(int i, int j, int k){
	return s[i][j] - '0' + s[i + dx[k]][j] - '0' + s[i][j + dy[k]] - '0';
}

int mn;

void add(int i, int j){
	for(int k = 0;k < 4;k++){
		if(i + dx[k] >= 1 && i + dx[k] <= n && j + dy[k] >= 1 && j + dy[k] <= m){
			mn = min(mn, get(i, j, k));
		}
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
		mn = 1e9;
		int sum = 0; 
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) add(i, j), sum += s[i][j] - '0';
		if(mn == 2) sum--;
		if(mn == 3) sum -= 2;
		printf("%d\n", sum);
	}
}