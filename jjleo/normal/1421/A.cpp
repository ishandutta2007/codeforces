#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a, b;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		ans = 0;
		for(int i = 1 << 30;i;i >>= 1){
			if((a & i) != (b & i)) ans += i; 
		}
		printf("%d\n", ans);
	}
}