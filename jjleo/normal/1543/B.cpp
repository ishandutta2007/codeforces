#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n, x;
ll sum;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), sum = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &x), sum += x;
		printf("%lld\n", sum % n * (n - sum % n));
	}
}