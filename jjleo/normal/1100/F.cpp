#include <bits/stdc++.h>
#define maxn 500086 
using namespace std;

int n, q, x, y;
int b[maxn][31], pos[maxn][31];//debug: 

inline void insert(int x, int y){
	int z = y;
	for(int i = 30, j = 1 << 30;j;i--, j >>= 1){
		if(x & j){
			if(!b[y][i]){
				b[y][i] = x, pos[y][i] = z;
				break;
			}else{
				if(z > pos[y][i]) swap(x, b[y][i]), swap(z, pos[y][i]);
				x ^= b[y][i];
			}
		}
	}
}

inline int query(int l, int r){
	int ans = 0;
	for(int i = 30;~i;i--){
		//printf("%d %d %d--\n", i, b[r][i], pos[r][i]);
		if(pos[r][i] >= l && (ans ^ b[r][i]) > ans) ans ^= b[r][i];
	}
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		//for(int j = 0;j <= 30;j++) b[i][j] = b[i - 1][j], pos[i][j] = pos[i - 1][j];
		memcpy(b[i], b[i - 1], sizeof(b[i - 1])), memcpy(pos[i], pos[i - 1], sizeof(pos[i - 1]));
		scanf("%d", &x);
		insert(x, i);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &x, &y);
		printf("%d\n", query(x, y));
	}
}