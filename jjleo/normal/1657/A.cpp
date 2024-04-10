#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		if(x == 0 && y == 0) puts("0");
		else if((int)sqrt(x * x + y * y) * (int)sqrt(x * x + y * y) == x * x + y * y) puts("1");
		else puts("2");
	}
}