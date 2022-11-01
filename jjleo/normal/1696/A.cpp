#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, z, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &z);
		int ans = 0;
		while(n--) scanf("%d", &x), ans = max(ans, x | z);
		printf("%d\n", ans);
	}
}