#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	ll ans = 1e18;
	for(int i = 1;i <= n;i++){
		ll sum = 0;
		ll last = 0;
		for(int j = i - 1;j;j--){
			last++;
			sum += (last + a[j] - 1) / a[j];
			last = (last + a[j] - 1) / a[j] * a[j];
		}
		last = 0;
		for(int j = i + 1;j <= n;j++){
			last++;
			sum += (last + a[j] - 1) / a[j];
			last = (last + a[j] - 1) / a[j] * a[j];
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
}