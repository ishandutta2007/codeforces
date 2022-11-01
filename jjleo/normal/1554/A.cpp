#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
long long a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long ans = 0;
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		for(int i = 1;i < n;i++) ans = max(ans, a[i] * a[i + 1]);
		printf("%lld\n", ans);
	}
}