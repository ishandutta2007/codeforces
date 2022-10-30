#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int n, m;
int a[maxn][10];
int x, y;

int id[1 << 9];

inline bool check(int mid){
	memset(id, 0, sizeof(id));
	for(int i = 1;i <= n;i++){
		int X = 0;
		for(int j = 1, k = 1;j <= m;j++, k <<= 1){
			if(a[i][j] >= mid) X += k;
		}
		for(int j = X;j;j = (j - 1) & X) id[j] = i;id[0] = i;
		int Y = X ^ ((1 << m) - 1);
		if(id[Y]){
			x = i, y = id[Y];
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[i][j]);
	int l = 0, r = 1e9, mid;
	while(l < r){
		if(check(mid = (l + r >> 1) + 1)) l = mid;
		else r = mid - 1;
	}
	check(l);
	printf("%d %d", x, y);
}