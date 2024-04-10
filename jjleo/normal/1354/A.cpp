#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		a -= b;
		if(a <= 0){
			printf("%d\n", b);
			continue;
		}
		if(c <= d){
			puts("-1");
			continue;
		}
		printf("%lld\n", b + 1ll * c * (a / (c - d) + (a % (c - d) != 0)));
	}
}