#include <bits/stdc++.h>
#define maxn 500086
using namespace std;

const int p = 998244353;

int n, k, m;
int l[maxn], r[maxn], x[maxn];
int f[maxn], maxl[maxn];
int der[maxn];
int ans = 1;

int main(){
	scanf("%d%d%d", &n, &k, &m);
	k--;//debug:<2^k 
	for(int i = 1;i <= m;i++) scanf("%d%d%d", &l[i], &r[i], &x[i]);
	for(int s = 1 << k;s;s >>= 1){
		memset(der, 0, sizeof(der));
		memset(maxl, 0, sizeof(maxl));
		memset(f, 0, sizeof(f));//debug: 
		for(int i = 1;i <= m;i++){
			if(x[i] & s){
				der[l[i]]++, der[r[i] + 1]--;
			}else{
				maxl[r[i] + 1] = max(maxl[r[i] + 1], l[i]);
			}
		}
		for(int i = 1;i <= n + 1;i++) der[i] += der[i - 1]; 
		for(int i = 1;i <= n + 1;i++) maxl[i] = max(maxl[i], maxl[i - 1]);//, printf("%d ", maxl[i]);puts("");
		f[0] = 1;
		int j = 0, sum = 1;//debug:sumf[0]1 
		for(int i = 1;i <= n + 1;i++){
			if(der[i]) continue;
			while(j < maxl[i]){
				sum += p - f[j++];
				if(sum >= p) sum -= p;
			}
			f[i] = sum;
			sum += f[i];
			if(sum >= p) sum -= p;
		}
		ans = 1ll * ans * f[n + 1] % p;
	}
	printf("%d", ans);
}