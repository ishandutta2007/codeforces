#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
ll a[maxn], b[maxn], sum, ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld", &b[i]), sum += a[i] * b[i];
	for(int i = 1;i <= n;i++){
		ll val = 0;
		for(int j = 1;i - j >= 1 && i + j <= n;j++){
			val += (a[i - j] - a[i + j]) * (b[i + j] - b[i - j]);
			ans = max(ans, val);
		} 
		val = 0;
		for(int j = 1;i - j + 1 >= 1 && i + j <= n;j++){
			val += (a[i - j + 1] - a[i + j]) * (b[i + j] - b[i - j + 1]);
			ans = max(ans, val);
		} 
	}
	printf("%lld", ans + sum);
}