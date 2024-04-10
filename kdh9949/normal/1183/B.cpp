#include <bits/stdc++.h>
using namespace std;

int main(){
	int q, n, k, l, r;
	scanf("%d", &q);
	while(q--){
		scanf("%d%d", &n, &k);
		l = 1; r = int(1e9);
		for(int x; n--; ){
			scanf("%d", &x);
			l = max(l, x - k);
			r = min(r, x + k);
		}
		if(l > r) puts("-1");
		else printf("%d\n", r);
	}
}