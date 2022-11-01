#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
ll n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &n);
		ll x = n;
		int cnt = 0;
		ll y;
		for(ll i = 2;i * i <= n;i++){
			int c = 0;
			while(x % i == 0){
				x /= i;
				c++;
			}
			if(c > cnt) cnt = c, y = i;
		}
		if(x != 1 && 1 > cnt) cnt = 1, y = x;
		printf("%d\n", cnt);
		for(int i = 1;i < cnt;i++){
			printf("%lld ", y);
			n /= y;
		}
		printf("%lld\n", n);
	}
}