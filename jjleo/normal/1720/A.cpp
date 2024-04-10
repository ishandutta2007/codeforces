#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if(1ll * a * d == 1ll * b * c){
			puts("0");
			continue; 
		}
		if(a == 0 || c == 0 || 1ll * a * d % (1ll * b * c) == 0 || 1ll * b * c % (1ll * a * d) == 0){
			puts("1");
			continue; 
		}
		puts("2");
	}
}