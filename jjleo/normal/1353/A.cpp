#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(n == 1) puts("0");
		else if(n == 2) printf("%d\n", m);
		else printf("%d\n", m * 2);
	}
}