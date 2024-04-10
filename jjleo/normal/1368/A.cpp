#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
long long a, b, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld", &a, &b, &n);
		int ans = 0;
		while(a <= n && b <= n){
			if(a > b) swap(a, b);
			a += b;
			ans++;
		}
		printf("%d\n", ans);
	}
}