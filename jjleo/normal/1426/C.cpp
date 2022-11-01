#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int ans = n - 1, sn = (int)sqrt(n); 
		if(sn * sn == n) ans = min(ans, 2 * sn - 2);
		else if((sn + 1) * sn >= n) ans = min(ans, 2 * sn - 1);
		else ans = min(ans, 2 * sn);
		printf("%d\n", ans);
	}
}