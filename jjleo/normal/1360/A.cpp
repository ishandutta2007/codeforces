#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		if(min(a + a, b + b) * 2 >= max(a + a, b + b)) printf("%d\n", min(a + a, b + b) * min(a + a, b + b));
		else printf("%d\n", max(a, b) * max(a, b));
	}
}