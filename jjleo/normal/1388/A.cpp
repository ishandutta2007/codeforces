#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		if(n <= 30) puts("NO");
		else{
			if(n == 36) printf("YES\n%d %d %d %d\n", 6, 10, 15, n - 31);
			else if(n == 40) printf("YES\n%d %d %d %d\n", 6, 10, 15, n - 31);
			else if(n == 44) printf("YES\n%d %d %d %d\n", 6, 10, 15, n - 31);
			else printf("YES\n%d %d %d %d\n", 6, 10, 14, n - 30);
		}
	} 
}