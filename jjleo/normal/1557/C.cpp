#include <bits/stdc++.h>
#define maxn 200086

const int p = 1e9 + 7;

using namespace std;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k == 0){
			puts("1");
			continue;
		}
		int ans = 1;
		if(n & 1){
			int pw = 1;
			for(int i = 1;i < n;i++) pw = (pw + pw) % p;
			for(int i = 1;i <= k;i++) ans = 1ll * ans * (pw + 1) % p;
		}else{
			int pw = 1, sum = 1;
			for(int i = 1;i < n;i++) pw = (pw + pw) % p;
			for(int i = 1;i < k;i++) sum = 1ll * sum * (pw + p - 1) % p;
			ans = 1ll * sum * (pw + p - 1) % p;
			int inv = fpow((pw + p - 1) % p, p - 2);
			for(int i = 1;i <= k;i++){
				ans = (ans + sum) % p;
				sum = 2ll * sum * inv % p * pw % p;
			}
		}
		printf("%d\n", ans);
	}
	
}