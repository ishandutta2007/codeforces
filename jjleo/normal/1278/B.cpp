#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		int x = abs(a - b);
		a = 0;
		if(!x){
			puts("0");
			continue;
		}
		for(int i = 1;;i++){
			a += i;
			if(!((a + x) & 1) && ((a + x) / 2 <= a)){
				printf("%d\n", i);
				break;
			}
		}
	}
}