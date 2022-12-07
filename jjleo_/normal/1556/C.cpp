#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	long long ans = 0;
	for(int i = 1;i < n;i += 2){
		long long sum = 0, mn = 1e18;
		for(int j = i + 1;j <= n;j += 2){
			ans += max(0ll, min(1ll * a[i], a[j] - sum) - max(-mn, 1 - sum) + 1);
			mn = min(mn, sum - a[j]);
			sum += -a[j] + a[j + 1];
		}
	}
	printf("%lld", ans);
}