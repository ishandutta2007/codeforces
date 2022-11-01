#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
long long a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		sort(a + 1, a + 1 + n);
		long long ans = a[n];
		for(int i = 2;i <= n;i++){
			ans -= a[i] * (i - 1) - a[i - 1];
			a[i] += a[i - 1]; 
		}
		printf("%lld\n", ans);
	}
}