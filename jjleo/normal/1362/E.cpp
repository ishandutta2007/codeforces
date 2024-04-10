#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

const int p = 1e9 + 7;

int t;
int n, m;
int a[maxn];
int cnt[maxn];

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
} 


int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		if(m == 1){
			for(int i = 1;i <= n;i++) cnt[a[i]] = 0;
			printf("%d\n", n & 1);
			continue;
		}
		sort(a + 1, a + 1 + n);
		int n0 = unique(a + 1, a + 1 + n) - (a + 1);
		int sum = n, ans = 0, need = 0;
		for(int j = n0;j;j--){
			int i = a[j];
			if(need){
				if(need <= sum){
					for(int k = i;k < a[j + 1];k++){
						if(1ll * need * m > sum){
							need = n + 1;
							break;
						}
						else need *= m;
					}
				}
				if(need > sum){
					ans += p - 1ll * cnt[i] * fpow(m, i) % p; 
					if(ans >= p) ans -= p;
					cnt[i] = 0;
				}else{
					int x = min(need, cnt[i]);
					sum -= x, cnt[i] -= x, need -= x;
					ans += p - 1ll * x * fpow(m, i) % p; 
					if(ans >= p) ans -= p;
				}
			}
			if(cnt[i] & 1){
				ans += fpow(m, i);
				if(ans >= p) ans -= p;
				need = 1;
			}
			sum -= cnt[i];
		}
		printf("%d\n", ans);
		for(int i = 1;i <= n0;i++) cnt[a[i]] = 0;
	}
}