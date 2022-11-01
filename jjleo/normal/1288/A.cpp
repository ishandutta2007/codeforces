#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &d);
		if(d <= n){
			puts("YES");
			continue;
		}
		int x = (int)sqrt(d);
		if(x <= n && x + d / (x + 1) + (d % (x + 1) != 0) <= n){
			puts("YES");
			continue;
		}
		x++;
		if(x <= n && x + d / (x + 1) + (d % (x + 1) != 0) <= n){
			puts("YES");
			continue;
		}
		x++;
		if(x + d / (x + 1) + (d % (x + 1) != 0) <= n){
			puts("YES");
			continue;
		}
		x = (int)sqrt(d) - 1;
		if(x > 0 && x + d / (x + 1) + (d % (x + 1) != 0) <= n){
			puts("YES");
			continue;
		}
		x--;
		if(x > 0 && x + d / (x + 1) + (d % (x + 1) != 0) <= n){
			puts("YES");
			continue;
		}
		puts("NO");
	}
}