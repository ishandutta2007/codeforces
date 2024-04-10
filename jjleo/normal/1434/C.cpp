#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
long long a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(a > b * c){
			puts("-1"); 
			continue;
		}
		printf("%lld\n", ((a - 1) / (b * d) + 1) * a - d * b * ((a - 1) / (b * d) + 1) * ((a - 1) / (b * d)) / 2);
	} 
}