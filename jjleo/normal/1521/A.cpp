#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
long long a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &a, &b);
		if(b == 1){
			puts("NO");
			continue;
		}
		printf("YES\n%lld %lld %lld\n", a, a * b, a * (b + 1));
	}
}