#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a, b, c, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &c, &r);
		if(a > b) swap(a, b);
		int x = max(a, c - r), y = min(b, c + r);
		if(x > y) printf("%d\n", b - a);
		else printf("%d\n", b - a - (y - x));
	}
}