#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		int x = (int)(sqrt(n) + 1);
		if(x > n) x = n;
		int ans = 2e9;
		for(int i = x;i;i--){
			if(n % i == 0){
				if(i <= k) ans = min(ans, n / i);
				if(n / i <= k) ans = min(ans, i);
			}
		}
		printf("%d\n", ans);
	} 
}