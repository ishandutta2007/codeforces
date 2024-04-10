#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 1e9 + 7;

int n;
int ans, sum;

int main(){
	scanf("%d", &n);
	ans = sum = 1;
	for(int i = 1;i <= n;i++) ans = 1ll * ans * i % p;
	for(int i = 1;i < n;i++) sum = 1ll * sum * 2 % p;
	printf("%d", (ans + p - sum) % p);
}