#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;

int main(){
	int a, b, c, d;
	int x, y, x1, y1, x2, y2;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &x, &y, &x1, &y1, &x2, &y2);
		if((a || b) && x1 == x2){
			puts("No");
			continue;
		}
		if((c || d) && y1 == y2){
			puts("No");
			continue;
		}
		if(a > b){
			if(a - b > x - x1){
				puts("No");
				continue;
			}
		}else{
			if(b - a > x2 - x){
				puts("No");
				continue;
			}
		}
		if(c > d){
			if(c - d > y - y1){
				puts("No");
				continue;
			}
		}else{
			if(d - c > y2 - y){
				puts("No");
				continue;
			}
		}
		puts("Yes");
	}
}