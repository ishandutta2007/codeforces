#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll inf = 1000000;

ll k;

int main()
{
	scanf("%lld",&k);
	for(ll i=2;i<=2000;i++) {
		ll X = (k + i - 1) / (i - 1);
		ll Y = ((i - 1) * X - 1 - k) + X + 1;
		if(X > inf || Y > inf) continue;
		printf("%lld\n",i);
		for(ll j=1;j<=i-2;j++) {
			printf("0 ");
		}
		printf("%lld %lld ", X-Y, Y);
		return 0;
	}
	puts("-1");
}