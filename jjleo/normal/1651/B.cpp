#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n > 19){
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i = 1, j = 1;i <= n;i++, j *= 3) printf("%d ", j);puts("");
	}
}