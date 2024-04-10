#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[30];
int x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			for(int j = 0;j < 30;j++) a[j] += (x & (1 << j)) != 0;
		}
		x = 0;
		for(int i = 0;i < 30;i++) x = __gcd(x, a[i]);
		for(int i = 1;i <= n;i++) if(x % i == 0) printf("%d ", i);
		puts(""); 
	}
}