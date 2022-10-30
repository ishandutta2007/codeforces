#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n & 1){
			puts("0");
			continue;
		}
		int x = 1;
		for(int i = 1;i <= n / 2;i++) x = 1ll * x * i % p * i % p;
		printf("%d\n", x);
	}
}