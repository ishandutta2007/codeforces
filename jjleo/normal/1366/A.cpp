#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		int ans = 0;
		if(a > b) swap(a, b);
		if(a * 2 >= b){
			printf("%d\n", (a + b) / 3);
			continue;
		}
		ans += min(a, b / 2);
		a -= ans, b -= ans * 2;
		printf("%d\n", ans + min(b, a / 2));
	} 
}