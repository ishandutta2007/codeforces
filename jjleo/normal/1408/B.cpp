#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		int x = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(i == 1 || a[i] != a[i - 1]) x++;
		}
		if(x > 1 && k == 1){
			puts("-1");
			continue;
		}
		if(x == 1 || k == 1) puts("1");
		else printf("%d\n", (x - 1 + k - 2) / (k - 1));
	}
}