#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n, k;

int main()
{
	scanf("%lld%lld",&k,&n);
	ll X = 0;
	for(ll i=1;i<=n;i++) {
		ll T;
		scanf("%lld",&T);
		if(k % 2 == 1 || i == n) X = (X + T) % 2;
	}
	puts(X ? "odd" : "even");
}