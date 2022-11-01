#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, k;
ll a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0;i < n;i++) scanf("%lld", &a[i]); 
		ll ans = 0; 
		for(int i = 1;i < n;i++){
			if(100 * a[i] > k * a[i - 1]){
				ll val = (100 * a[i] - k * a[i - 1] + k - 1) / k;
				a[i - 1] += val;
				ans += val; 
			}
			a[i] += a[i - 1];
		}
		printf("%lld\n", ans);
	}
}