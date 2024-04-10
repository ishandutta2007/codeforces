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
		int ans = 0, pw = 1;
		while(k){
			if(k & 1) ans = (ans + pw) % p;
			pw = 1ll * pw * n % p, k >>= 1;
		}
		printf("%d\n", ans);
	}
}