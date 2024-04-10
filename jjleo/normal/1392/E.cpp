#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, q;
ll x;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++) printf("%lld ", i & 1 ? (1ll << (i + j)) : 0);
		puts(""), fflush(stdout);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%lld", &x);
		int i = 1, j = 1;
		printf("%d %d", i, j);
		puts(""), fflush(stdout);
		while(i != n || j != n){
			if(((i + 1) & 1) == ((x & (1ll << (i + j + 1))) != 0)) i++;
			else j++;
			printf("%d %d", i, j);
			puts(""), fflush(stdout);
		}
	}
}