#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		for(int i = 0;i < n;i++){
			printf("%d\n", i ? (i ^ (i - 1)) : 0), fflush(stdout);
			scanf("%d", &x);
			if(x) break;
		}
	}
}