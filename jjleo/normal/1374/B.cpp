#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n == 1){
			puts("0");
			continue;
		}
		int x = 0, y = 0;
		while(n % 2 == 0) n /= 2, x++;
		while(n % 3 == 0) n /= 3, y++;
		if(x > y || n != 1){
			puts("-1");
			continue;
		}
		printf("%d\n", y - x + y);
	}
}