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
		if(a == b){
			puts("0 0");
			continue;
		}
		if(a < b) swap(a, b);
		printf("%lld %lld\n", a - b, min(b % (a - b), a - b - (b % (a - b))));
	}
}