#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int t;
int n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		int ans = 1;
		for(int i = 1;i <= k;i++) ans = 1ll * ans * n % p;
		printf("%d\n", ans);
	}
}