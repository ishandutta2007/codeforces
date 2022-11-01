#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &k);
		int gcd = __gcd(k, 100);
		printf("%d\n", k / gcd + (100 - k) / gcd);
	}
}