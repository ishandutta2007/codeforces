#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll n;

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		ll T, X;
		scanf("%lld",&T);
		for(X=1;X<=T;X*=2);
		if(T != X-1) {
			printf("%lld\n",X-1);
			continue;
		}
		bool F = false;
		for(ll j=2;j*j<=T;j++) {
			if(T % j == 0) {
				printf("%lld\n", T/j);
				F = true;
				break;
			}
		}
		if(!F) printf("1\n");
	}
}