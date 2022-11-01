#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x, y;
int ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &x);
		ans = 1e9;
		while(n--){
			scanf("%d", &y);
			if(y > x) ans = min(ans, 2);
			else ans = min(ans, x / y + (x % y != 0));
		}
		printf("%d\n", ans); 
	}
}