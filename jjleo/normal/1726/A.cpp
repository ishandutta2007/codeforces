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
		if(n == 1){
			puts("0");
			continue; 
		}
		int ans = -1e9;
		for(int i = 1;i <= n;i++){
			int j = n + i - 1;
			if(j > n) j -= n;
			ans = max(ans, a[j] - a[i]);
		}
		for(int i = 2;i <= n;i++) ans = max(ans, a[i] - a[1]);
		for(int i = 1;i < n;i++) ans = max(ans, a[n] - a[i]);
		printf("%d\n", ans);
	}
}