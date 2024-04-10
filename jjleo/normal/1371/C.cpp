#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
long long a, b, n, m;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
		if(a + b < n + m){
			puts("No");
			continue;
		}
		if(min(a, b) < m){
			puts("No");
			continue;
		}
		puts("Yes");
		
	}
}