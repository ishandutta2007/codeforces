#include <bits/stdc++.h>
#define maxn 2000086

using namespace std;

const int p = 998244353, inv2 = 499122177;

inline void XOR(int *a, int lim, int type){
	for(register int mid = 1;mid < lim;mid <<= 1){
		for(register int i = mid << 1, j = 0;j < lim;j += i){
			for(register int k = 0;k < mid;k++){
				a[j + k] += a[j + k + mid];
				if(a[j + k] >= p) a[j + k] -= p;
				a[j + k + mid] = a[j + k] - a[j + k + mid] - a[j + k + mid];//debug:=+= 
				if(a[j + k + mid] >= p) a[j + k + mid] -= p;
				else while(a[j + k + mid] < 0) a[j + k + mid] += p;
				if(type == -1) a[j + k] = 1ll * a[j + k] * inv2 % p, a[j + k + mid] = 1ll * a[j + k + mid] * inv2 % p;
			}
		}
	}
}

int n, m, lim;
char s[25][maxn];
int a[maxn], b[maxn];
int ans = 0x3f3f3f3f;

int main(){
	scanf("%d%d", &n, &m), lim = 1 << n;
	for(int i = 1;i <= n;i++) scanf("%s", s[i] + 1);
	for(int i = 1;i <= m;i++){
		int sum = 0;
		for(int j = 1, k = 1;j <= n;j++, k <<= 1) if(s[j][i] == '1') sum += k;
		++a[sum];
	}
	for(int i = 1;i <= lim;i++){
		for(int j = i;j;j >>= 1) if(j & 1) ++b[i];
		b[i] = min(b[i], n - b[i]);
	}
	XOR(a, lim, 1), XOR(b, lim, 1);
	for(int i = 0;i < lim;i++) a[i] = 1ll * a[i] * b[i] % p;
	XOR(a, lim, -1);
	for(int i = 0;i < lim;i++) ans = min(ans, a[i]);
	printf("%d", ans);
}