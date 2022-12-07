#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		int ans = 0;
		if(n < k) ans += k - n, n = k;
		ans += (n + k) & 1;
		printf("%d\n", ans);
	}
	
}