#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int x, y, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if((y - x) % (a + b)){
			puts("-1");
			continue;
		}
		printf("%d\n", (y - x) / (a + b));
	}
}