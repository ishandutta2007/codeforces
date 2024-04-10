#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll p,q,r,s;
ll gcd(ll x,ll y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&p,&q,&r);
		s=gcd(p,q);
		q/=s;
		for(;;)
		{
			s=gcd(q,r);
			if(s==1)break;
			while(q%s==0)q/=s;
		}
		if(q>1)puts("Infinite");
		else puts("Finite");
	}
	return 0;
}