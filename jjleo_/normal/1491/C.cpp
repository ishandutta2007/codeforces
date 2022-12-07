#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn];
ll f[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), f[i] = 0;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(i == n){
				f[i] -= a[i] - 1;
				a[i] = 1;
			}else{
				if(i + a[i] > n){
					f[i] -= i + a[i] - n;
					a[i] -= i + a[i] - n;
				}
			}
			for(int j = 2;j <= a[i];j++){
				f[i + j]++;
				f[i]--;
			}
			if(f[i] < 0) ans -= f[i], f[i] = 0;
			f[i + 1] += f[i];
		}
		printf("%lld\n", ans);
	}
}