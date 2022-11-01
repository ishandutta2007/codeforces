#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int l, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &l, &r);
		if(2 * l > r) puts("-1 -1");
		else printf("%d %d\n", l, 2 * l);
	}
}