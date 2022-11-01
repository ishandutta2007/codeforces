#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;

int main(){
	scanf("%d", &t);
	int x1, y1, x2, y2;
	while(t--){
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if(x1 == x2 || y1 == y2){
			printf("%d\n", abs(x1 - x2) + abs(y1 - y2));
		}else{
			printf("%d\n", abs(x1 - x2) + abs(y1 - y2) + 2);
		}
	}
}