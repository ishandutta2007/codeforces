#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll a, b;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &a, &b);
		if(a > b) swap(a, b);
		if(b % a){
			puts("-1");
			continue;
		} 
		ll x = b / a;
		int y = 0;
		while(x % 8 == 0) x /= 8, y++;
		while(x % 4 == 0) x /= 4, y++;
		while(x % 2 == 0) x /= 2, y++;
		if(x ^ 1){
			puts("-1");
			continue;
		}
		printf("%d\n", y);
	}
}