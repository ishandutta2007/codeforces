#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &x);
		n = 10 - n;
		printf("%d\n", n * (n - 1) / 2 * 6);
	}
}