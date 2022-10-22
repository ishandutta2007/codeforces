#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
ll n,m,o,x;
ll work(ll m,ll x)
{
	if(x&1)return n-(1LL<<m)+(x+1>>1);
	return work(m-1,x>>1);
}
int main()
{
	scanf("%I64d%d",&n,&q);
	for(m=0;1LL<<m<=n;m++);
	m--;
	o=n-(1LL<<m)<<1;
	while(q--)
	{
		scanf("%I64d",&x);
		if(x<=o)if(x&1)printf("%I64d\n",x+1>>1);
		else printf("%I64d\n",work(m,n-o+(x>>1)));
		else printf("%I64d\n",work(m,x-o));
	}
	return 0;
}