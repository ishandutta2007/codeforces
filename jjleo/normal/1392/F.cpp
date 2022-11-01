#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
long long x, sum;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &x), sum += x - i;
	for(int i = 1;i <= n;i++) printf("%lld ", i + sum / n + (i <= sum % n));
	
}