#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll cnt,ccnt,sum,tot,cur;
ll num[MAXN],length[MAXN];
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
    cnt=read(),ccnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i]=read();
		sum+=num[i];
	}
	if(sum%ccnt)
	{
		puts("No");
		return 0;
	}
	sum/=ccnt;
	for(register int i=0;i<cnt;)
	{
		while(cur<sum)
		{
			cur+=num[i],i++,length[tot]++;
		}
		if(cur!=sum)
		{
			puts("No");
			return 0;
		}
		tot++,cur=0;
	}
	puts("Yes");
	for(register int i=0;i<tot;i++)
	{
		printf("%d ",length[i]);
	}
}