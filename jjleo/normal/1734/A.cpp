#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 2e9;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) for(int k = 1;k <= n;k++) if(i != j && j != k && i != k) ans = min(ans, abs(a[i] - a[j]) + abs(a[i] - a[k]));
		printf("%d\n", ans);
	}
}