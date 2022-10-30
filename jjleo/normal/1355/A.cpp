#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
long long a, k;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%lld%lld", &a, &k);
		for(int i = 1;i < k;i++){
			int mx = 0, mn = 9;
			long long b = a;
			while(b) mx = max(1ll * mx, b % 10), mn = min(1ll * mn, b % 10), b /= 10;
			if(mx * mn == 0) break;
			a += mn * mx;
		}
		printf("%lld\n", a);
	} 
}