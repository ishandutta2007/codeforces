#include <bits/stdc++.h>
#define maxn 1000086
using namespace std;

int n, k;
int f[maxn];
int a[maxn]; 

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	n = unique(a + 1, a + 1 + n) - (a + 1);
	for(int i = 2;i <= n;i++) a[i] -= a[1];
	memset(f, 0x3f, sizeof(f)), f[0] = 0;
	for(int i = 2;i <= n;i++){
		for(int j = 1;j < maxn;j++){//debug:  
			if(j - a[i] >= 0) f[j] = min(f[j], f[j - a[i]] + 1);
		}
	}
	for(int i = 0;i < maxn;i++) if(f[i] <= k) printf("%d ", i + a[1] * k);
}