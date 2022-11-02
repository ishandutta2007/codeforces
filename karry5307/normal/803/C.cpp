#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll num,cnt;
vector<ll>factor;
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline ll check(ll n)
{
	ll sum=num/n,k=(cnt-1)*cnt>>1;
	if(sum-k>=cnt)
	{
		for(register int i=1;i<cnt;i++)
		{
			printf("%lld ",i*n);
		}
		printf("%lld\n",(sum-k)*n);
		return 1;
	}
	return 0;
}
int main()
{
	num=read(),cnt=read();
	if((num<<1)/cnt<cnt+1)
	{
		puts("-1");
		return 0;
	}
	for(register ll i=1;i*i<=num;i++)
	{
		if(!(num%i))
		{
			factor.push_back(i);
			if(num-i*i)
			{
				factor.push_back(num/i);
			}
		}
	}
	sort(factor.begin(),factor.end(),greater<ll>());
	for(register int i=0;i<factor.size();i++)
	{
		if(check(factor[i]))
		{
			return 0;
		}
	}
	puts("-1");
}