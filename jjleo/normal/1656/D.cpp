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
		if(n == 2 || n == 4){
			puts("-1");
			continue;
		}
		ll N = n;
		ll pw = 2;
		while(!(n & 1)) pw <<= 1, n >>= 1;
		if((__int128)pw * (pw + 1) / 2 <= N) printf("%lld\n", pw);
		else if(n > 1 && (__int128)n * (n + 1) / 2 <= N) printf("%lld\n", n);
		else puts("-1"); 
	}
}