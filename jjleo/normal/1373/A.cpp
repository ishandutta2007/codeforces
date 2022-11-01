#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b, c;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a, &b, &c);
		if(a >= c) printf("-1 ");
		else printf("1 ");
		if(1ll * a * b <= c) puts("-1");
		else printf("%d\n", b);
	}
}