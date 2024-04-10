#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define iter iterator  
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt,res,x,rr,pp,cur;
ll p[MAXN],q[MAXN],r[MAXN];
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
inline ll get(ll x)
{
	for(register ll i=0;i<31;i++)
	{
		if(x&(1ll<<i)) 
		{
			return i;
		}
	}
	return 0;
}
inline void solve()
{
	x=read(),cnt=read(),res=rr=pp=cur=0;
	memset(p,0,sizeof(p)),memset(q,0,sizeof(q)),memset(r,0,sizeof(r));
	for(register int i=0;i<cnt;i++)
	{
		p[i]=read();
	}
	sort(p,p+cnt);
	for(register int i=0;i<cnt;i++)
	{
		q[get(p[i])]++;
	}
	for(register int i=0;i<63;i++)
	{
		if(x&(1ll<<i))
		{
			r[i]++;
		}
	}
	for(register int i=0;i<63;i++)
	{
		cur+=(q[i]<<i);
		if(~rr&&pp<=cur)
		{
			res+=(i-rr),cur-=pp,rr=-1;
		}
		if(r[i])
		{
			if((1ll<<i)>cur)
			{
				pp+=(1ll<<i);
				if(!(~rr))
				{
					rr=i;
				}
			}
			else
				{
					cur-=(1ll<<i);
				}
		}
	}
	cout<<(~rr?-1:res)<<endl;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}