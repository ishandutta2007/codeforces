#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		ll x = 9, y = 0;
		while(x <= b){
			y++;
			x = x * 10 + 9;
		}
		printf("%lld\n", y * a);
	}	
}