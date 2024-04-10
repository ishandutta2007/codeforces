#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, x, y;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &x, &y);
		if(x > y) swap(x, y);//i + n > x + y, i = x + y + 1 - n, i - 1 + 1 = x + y - n + 1 
		printf("%d %d\n", min(n, max(x + y - n + 1, 1)), max(min(x + y - 1, n), 1));
	}
}