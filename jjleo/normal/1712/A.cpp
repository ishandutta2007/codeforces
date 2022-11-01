#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		int ans = 0;
		for(int i = 1;i <= k;i++) ans += a[i] > k;
		printf("%d\n", ans);
	}
}