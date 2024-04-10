#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n;
int a[maxn], b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 1e9, y = 1e9;
		ll ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), x = min(x, a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]), y = min(y, b[i]);
		for(int i = 1;i <= n;i++) ans += a[i] - x + b[i] - y - min(a[i] - x , b[i] - y);
		printf("%lld\n", ans);
	} 
}