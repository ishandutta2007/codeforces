#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m), m++;
		int x = 0;
		for(int i = 29;~i;i--){
			if(!(n & (1 << i)) && (m & (1 << i))) x += 1 << i;
			else if((n & (1 << i)) && !(m & (1 << i))) break;
		}
		printf("%d\n", x);
	} 
}