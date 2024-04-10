#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		if(k == 1){
			printf("%d\n", (n - 2 + 1) / 2);
			continue; 
		}
		int ans = 0;
		for(int i = 2;i < n;i++) ans += a[i] > a[i - 1] + a[i + 1];
		printf("%d\n", ans);
	}
}