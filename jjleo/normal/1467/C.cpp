#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n1, n2, n3;
long long sum, Sum, ans = 1e18, mn1 = 1e9, mn2 = 1e9, mn3 = 1e9;
int x;

int main(){
	scanf("%d%d%d", &n1, &n2, &n3);
	
	Sum = 0;
	for(int i = 1;i <= n1;i++){
		scanf("%d", &x);
		sum += x, Sum += x;
		mn1 = min(mn1, 1ll * x);
	}
	ans = min(ans, Sum << 1);
	
	Sum = 0;
	for(int i = 1;i <= n2;i++){
		scanf("%d", &x);
		sum += x, Sum += x;
		mn2 = min(mn2, 1ll * x);
	}
	ans = min(ans, Sum << 1);
	
	Sum = 0;
	for(int i = 1;i <= n3;i++){
		scanf("%d", &x);
		sum += x, Sum += x;
		mn3 = min(mn3, 1ll * x);
	}
	ans = min(ans, Sum << 1);
	
	ans = min(ans, mn1 + mn2 << 1);
	ans = min(ans, mn1 + mn3 << 1);
	ans = min(ans, mn2 + mn3 << 1);
	printf("%lld", sum - ans);
}