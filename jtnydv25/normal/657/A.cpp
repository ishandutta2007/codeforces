#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
int main(){
	int n, d, h;
	sd(n), sd(d), sd(h);
	if((d > 2 * h) || (d == 1 && n != 2)){
		printf("-1");
		return 0;
	}
	int i = 2;
	for(; i <= h + 1; i++) printf("%d %d\n", i - 1, i);
	if(h == n - 1) return 0;
	if(h < d){
		printf("%d %d\n", 1, i);
		int mx = i + d - h - 1; i ++;
		for(; i <= mx; i ++) printf("%d %d\n", i - 1, i);
	}
	int node = (d == h) ? 2 : 1;
	for(; i <= n; i++) printf("%d %d\n", node, i);
}