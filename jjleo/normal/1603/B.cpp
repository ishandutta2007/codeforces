#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		if(x == y) printf("%d\n", x);
		else if(x > y) printf("%d\n", x + y);
		else printf("%d\n", (y / x * x + y) / 2); 
	}
}