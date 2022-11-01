#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if((n & 1) ^ (k & 1)){
			puts("NO");
			continue;
		}
		if(1ll * k * k > n){
			puts("NO");
			continue;
		}
		puts("YES");
	}
}