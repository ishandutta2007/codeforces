#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll solve (ll A, ll B) {
	if((A-B)%2==0) return (A-B)/2+1;
	else return (A-B+1)/2 + solve(A-(A-B+1)/2,1);
}

int main()
{
	scanf("%lld%lld",&n,&k);
	while(k--) {
		ll X;
		scanf("%lld",&X);
		printf("%lld\n",solve(n,n-X+1));
	}
}