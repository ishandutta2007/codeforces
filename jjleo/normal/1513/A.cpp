#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if((n - 1) / 2 < k){
			puts("-1");
			continue;
		}
		int x = n;
		for(int i = 1;i <= n;i++) a[i] = 0;
		for(int i = 2;i < n && k;i += 2, k--) a[i] = x--;
		for(int i = 1;i <= n;i++) if(!a[i]) a[i] = x--;
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts(""); 
	}
}