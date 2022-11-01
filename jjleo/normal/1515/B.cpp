#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n & 1){
			puts("NO");
			continue;
		}
		int x = sqrt(n / 2);
		if(x * x == n / 2){
			puts("YES");
			continue;
		}
		x = sqrt(n / 4);
		if(n % 4 == 0 && x * x == n / 4){
			puts("YES");
			continue;
		}
		puts("NO"); 
	}
}