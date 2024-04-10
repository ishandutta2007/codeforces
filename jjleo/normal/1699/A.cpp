#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n & 1) puts("-1");
		else printf("%d %d %d\n", n / 2, n / 2, 0);
	}
}