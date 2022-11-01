#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, r;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0, y = 0;
		while(n--){
			scanf("%d", &r);
			if(r == 1) x++;
			else if(r == 2) y--;
			else if(x >= 0) x++;
			else y--; 
		}
		printf("%d\n", x);
	}
}