#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		while(k > 3) n--, k--, printf("1 ");
		if(n & 1) printf("%d %d %d\n", 1, (n - 1) / 2, (n - 1) / 2);
		else if(n % 4 == 2) printf("%d %d %d\n", 2, (n - 2) / 2, (n - 2) / 2);
		else printf("%d %d %d\n", n / 4, n / 4, n / 2);
	}
}