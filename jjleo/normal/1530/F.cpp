#include <bits/stdc++.h>
#define maxn 21

using namespace std;

const int p = 31607;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = ans * x % p;
		x = x * x % p, y >>= 1;
	}
	return ans;
}

const int inv = fpow(10000, p - 2);

int n;
int a[maxn][maxn], id[1 << maxn];
int f[maxn][1 << maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) id[1 << i] = i;
	for(int i = 0;i < n;i++) for(int j = 0;j < n;j++) scanf("%d", &a[i][j]), a[i][j] = a[i][j] * inv % p;
	for(int j = 0;j < n;j++){
		f[j][0] = 1;
		for(int i = 1;i < (1 << n);i++){
			int k = i & -i;
			f[j][i] = f[j][i ^ k] * a[id[k]][j] % p;
		}
	}
	int ans = 1;
	for(int i = 0;i < (1 << (n + 2));i++){
		int sum = 1;
		for(int j = 0;j < n;j++){
			int k = i;
			if(k & (1 << n)) k |= 1 << j, k ^= 1 << n;
			if(k & (1 << (n + 1))) k |= 1 << (n - 1 - j), k ^= 1 << (n + 1);
			sum = sum * (f[j][k] + p - f[j][(1 << n) - 1]) % p;
		}
		if(__builtin_popcount(i) & 1) ans = (ans + sum) % p;
		else ans = (ans + p - sum) % p;
	}
	printf("%d", ans);
}