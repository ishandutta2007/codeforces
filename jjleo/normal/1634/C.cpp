#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(k == 1){
			puts("YES");
			for(int i = 1;i <= n;i++) printf("%d\n", i);
			continue;
		}
		if(n & 1){
			puts("NO");
			continue; 
		}
		puts("YES");
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= k;j++) printf("%d ", i & 1 ? (i - 1) * k + 2 * j - 1 : (i - 2) * k + 2 * j);
			puts("");
		}
	}
}