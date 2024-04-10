#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n, greater<int>());
		long long ans = 0;
		for(int i = 1;i <= k + 1;i++) ans += a[i];
		printf("%lld\n", ans);	
	}
}