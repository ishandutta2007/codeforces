#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0;
		for(int i = 1;i <= n;i++) for(int j = i;j <= n;j++) for(int k = i;k <= j;k++) ans += 1 + (a[k] == 0);
		printf("%d\n", ans);
	}
}