#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int x = 0;
		while(n) x = max(x, n % 10), n /= 10;
		printf("%d\n", x);
	}
}