#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, a[maxn]; 

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		long long ans = 0;
		for(int i = 2;i <= n;i++) if(a[i] < a[i - 1]) ans += a[i - 1] - a[i];
		printf("%lld\n", ans);
	}
}