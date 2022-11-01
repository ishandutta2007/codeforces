#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll cnt,ccnt,d,sum,r,cur,curr;
ll x[MAXN],res[MAXN];
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
int main()
{
	cnt=read(),ccnt=read(),d=read();
	for(register int i=1;i<=ccnt;i++)
	{
		sum+=(x[i]=read());
	}
	r=cnt-sum;
	if(sum==0||r>(d-1)*(ccnt+1))
	{
		return puts("NO"),0;
	}
	cur=1;
	while(curr<cnt)
	{
		if(r<d-1)
		{
			curr+=r+1,r=0;
			for(register int i=curr;i<=curr+x[cur]-1;i++)
			{
				res[i]=cur;
			}
			curr+=x[cur]-1,cur++;
		}
		else
		{
			curr+=d,r-=d-1;
			for(register int i=curr;i<=curr+x[cur]-1;i++)
			{
				res[i]=cur;
			}
			curr+=x[cur]-1,cur++;
		}
	}
	puts("YES");
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",res[i]);
	}
}