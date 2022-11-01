#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

char s[maxn];
int n, ans;
int f[maxn];

int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	f[0] = 1;
	for(int i = 1;i <= n;i++) f[i] = 1ll * f[i - 1] * 10 % p;
	for(int i = 1;i <= n;i++) f[i] = (f[i] + f[i - 1]) % p;
	int x = 0;
	for(int i = 1;i < n;i++){
		x = (1ll * x * 10 + s[i] - '0') % p;
		ans = (ans + 1ll * x * f[n - i - 1]) % p;
	}
	x = 0;
	f[0] = 1;
	for(int i = 1;i <= n;i++) f[i] = 1ll * f[i - 1] * 10 % p;
	for(int i = n;i;i--){
		x = (x + 1ll * f[n - i] * (s[i] - '0')) % p;
		ans = (ans + 1ll * x * (i - 1)) % p;
	}
	printf("%d", ans);
}