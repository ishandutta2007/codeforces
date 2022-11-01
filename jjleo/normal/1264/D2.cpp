#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1; 
	}
	return ans;
}

int sum[maxn], inv[maxn];

inline int C(int n, int m){
	if(n < m) return 0;
	return 1ll * sum[n] * inv[m] % p * inv[n - m] % p;
}

int n;
char s[maxn];
int cnt;
int a[2][maxn], ans;

int main(){
	sum[0] = 1;for(int i = 1;i < maxn;i++) sum[i] = 1ll * sum[i - 1] * i % p;
	inv[maxn - 1] = fpow(sum[maxn - 1], p - 2);
	for(int i = maxn - 2;~i;i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % p;
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1;i <= n;i++) cnt += s[i] == '?';
	for(int i = 0;i <= 1;i++){
		for(int j = 0;j < maxn;j++){
			a[i][j] = C(cnt - i, j);
			if(j) a[i][j] = (a[i][j] + a[i][j - 1]) % p;
		}
	}
	int A = 0, B = 0, t2 = cnt;
	for(int i = 1;i <= n;i++) B += s[i] == '(';
	for(int i = n;i;i--){
		if(s[i] == '('){
			B--;
			continue;
		}
		if(s[i] == ')'){
			if(B - A + t2 - 1 >= 0) ans = (ans + a[0][B - A + t2 - 1]) % p;
			A++;
		}else{
			t2--;
			if(B - A + t2 - 1 >= 0) ans = (ans + a[1][B - A + t2 - 1]) % p;
			
		}
	}
	printf("%d", ans);
}