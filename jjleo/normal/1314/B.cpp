#include <bits/stdc++.h>
#define maxn 4000086

using namespace std;

int n, k;
int a[maxn], x;
int f[maxn][4];

#define ls(x) (x << 1)
#define rs(x) (x << 1 | 1)

void solve(int x, int l, int r){
	if(l + 1 == r){
		f[x][a[l] | (a[r] << 1)] = f[x][a[r] | (a[l] << 1)] = a[l] | a[r];
		return;
	}
	int mid = l + r >> 1;
	solve(ls(x), l, mid), solve(rs(x), mid + 1, r);
	for(int a = 0;a < 4;a++){
		for(int b = 0;b < 4;b++){
			for(int i = 0;i <= 1;i++){
				for(int j = 0;j <= 1;j++){
					for(int k = 0;k <= 1;k++){
						int cnt = f[ls(x)][a] + f[rs(x)][b];
						cnt += (a & 1) | (b & 1);
						cnt += ((a >> 1) & 1) | ((b >> 1) & 1);
						cnt += (i ? b & 1 : a & 1) | (j ? (a >> 1) & 1 : (b >> 1) & 1);
						int c = (i ? a & 1 : b & 1) | ((k ? (i ? b & 1 : a & 1) : (j ? (a >> 1) & 1 : (b >> 1) & 1)) << 1);
						f[x][c] = max(f[x][c], cnt);
					}
				}
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &k);
	while(k--) scanf("%d", &x), a[x] = 1;
	memset(f, -0x3f, sizeof(f));
	solve(1, 1, 1 << n);
	printf("%d", max({f[1][0], f[1][1] + 1, f[1][2] + 1, f[1][3] + 1}));
}