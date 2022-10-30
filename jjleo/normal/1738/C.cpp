#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int t, n;
int f[maxn][maxn][2][2];

int main(){
	for(int i = 0;i < maxn;i++) for(int j = 0;j < maxn;j++) for(int k = 0;k <= 1;k++) for(int l = 0;l <= 1;l++){
		if(i == 0 && j == 0){
			f[i][j][k][l] = k ^ l ^ 1;
			continue;
		}
		if(i) f[i][j][k][l] |= !f[i - 1][j][k ^ 1][l];
		if(j) f[i][j][k][l] |= !f[i][j - 1][k ^ 1][l ^ (k == 0)];
	}
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x[2] = {0};
		while(n--){
			int y;
			scanf("%d", &y);
			x[y & 1]++;
		}
		puts(f[x[0]][x[1]][0][0] ? "Alice" : "Bob");
	}
}