#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if((n / 2) & 1){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1;i <= n / 2;i++) printf("%d ", i * 2);
		for(int i = 1;i < n / 2;i++) printf("%d ", i * 2 - 1);
		printf("%d\n", n - 1 + n / 2);
	}
}