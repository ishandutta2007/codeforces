#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main()
{
	scanf("%lld%lld",&n,&m);
	if(n > 60) printf("%lld\n",m);
	else printf("%lld\n",m%((1ll)<<n));
}