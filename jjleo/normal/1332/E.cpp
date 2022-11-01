#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const int p = 998244353;

inline ll fpow(ll x, ll y){
	ll ans = 1;
	while(y){
		if(y & 1) ans = ans * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ans;
}

ll n, m, l, r, j, o;

int main(){
	scanf("%lld%lld%lld%lld", &n, &m, &l, &r);
	j = o = (r - l + 1) / 2;
	if((r - l + 1) & 1){
		if(l & 1) j++;
		else o++;
	}
	if((n * m) & 1){
		printf("%lld", fpow(j + o, n * m));
	}else{
		printf("%lld", (fpow(j + o, n * m) + fpow(abs(j - o), n * m)) * fpow(2, p - 2) % p);
	}
}