#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, k;
char s[maxn];
int a[17][maxn], sum[maxn];
int f[1 << 17];

bool check(int len){
	for(int j = 0;j < k;j++){
		a[j][n + 1] = -1;
		for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + (s[i] == 'a' + j || s[i] == '?');
		for(int i = n;i;i--){
			if(i + len - 1 <= n && sum[i + len - 1] - sum[i - 1] == len) a[j][i] = i + len;
			else a[j][i] = a[j][i + 1];
		}
	}
	f[0] = 1;
	for(int i = 1;i < (1 << k);i++) f[i] = -1;
	for(int i = 0;i < (1 << k);i++){
		if(f[i] == -1) continue;
		for(int j = 0;j < k;j++){
			if((i & (1 << j)) || a[j][f[i]] == -1) continue;
			if(f[i | (1 << j)] == -1) f[i | (1 << j)] = a[j][f[i]];
			f[i | (1 << j)] = min(f[i | (1 << j)], a[j][f[i]]);
		}
	}
	return f[(1 << k) - 1] != -1;
}

int main(){
	scanf("%d%d%s", &n, &k, s + 1);
	int l = 0, r = n, mid;
	while(l < r){
		mid = (l + r >> 1) + 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	printf("%d", l);
}