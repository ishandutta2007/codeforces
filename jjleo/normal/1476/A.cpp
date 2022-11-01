#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		if(n <= k) printf("%d\n", (k + n - 1) / n);
		else printf("%d\n", n % k == 0 ? 1 : 2);
	}
}