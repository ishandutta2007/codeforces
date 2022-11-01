#include <bits/stdc++.h>
#define maxn 500086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int t;
int n;
ll a[maxn];
int cnt[60];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 1;i <= n;i++){
			scanf("%lld", &a[i]);
			for(int j = 0;j < 60;j++){
				if(a[i] & (1ll << j)) cnt[j]++;
			}
		}
		int ans = 0, x, y;
		for(int i = 1;i <= n;i++){
			x = y = 0;
			for(int j = 0, k = 1;j < 60;j++, k = (k + k) % p){
				if(a[i] & (1ll << j)){
					x = (x + 1ll * k * n) % p;
					y = (y + 1ll * k * cnt[j]) % p;
				}else{
					x = (x + 1ll * k * cnt[j]) % p;
				}
			}
			//printf("%lld %lld %lld--\n", a[i], x, y);
			ans = (ans + 1ll * x * y) % p;
		}
		printf("%d\n", ans); 
	}
}