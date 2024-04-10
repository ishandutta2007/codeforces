#include <bits/stdc++.h>
#define maxn 20086

using namespace std;

const int p = 998244353;

int n;
char s[maxn];
int a[23][26];
int f[1 << 23];
int b[26];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		for(int j = 1;j <= len;j++) a[i][s[j] - 'a']++;
	}
	for(int i = 1;i < (1 << n);i++){
		for(int k = 0;k < 26;k++) b[k] = 1e9;
		for(int j = 0;j < n;j++) if(i & (1 << j)){
			for(int k = 0;k < 26;k++){
				b[k] = min(b[k], a[j][k]);
			}
		}
		int val = 1;
		for(int k = 0;k < 26;k++) val = 1ll * val * (b[k] + 1) % p;
		f[i] = val;
		if(!(__builtin_popcount(i) & 1)) f[i] = (p - f[i]) % p;
	}
	for(int i = 0;i < n;i++) for(int j = 0;j < (1 << n);j++) if(j & (1 << i)) f[j] = (f[j] + f[j ^ (1 << i)]) % p;
	long long ans = 0;
	for(int i = 0;i < (1 << n);i++){
		int k = 0, sum = 0;
		for(int j = 0;j < n;j++) if(i & (1 << j)){
			k++, sum += j + 1;
		}
		ans ^= 1ll * f[i] * k * sum;
		//printf("%d %d--\n", i, f[i]);
	}
	printf("%lld", ans);
}