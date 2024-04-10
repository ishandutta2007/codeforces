#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Node{
	ll num,pos;
	inline bool operator <(const Node &rhs)const
	{
		return this->num>rhs.num;
	}
};
Node num[MAXN];
ll cnt,sum,tot;
ll res[MAXN];
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i].num=read(),num[i].pos=i+1;
		sum+=num[i].num;
	}
	sort(num,num+cnt);
	if(sum-num[0].num==(num[1].num<<1))
	{
		res[tot++]=num[0].pos;
	}
	for(register int i=1;i<cnt;i++)
	{
		if(sum-num[i].num==(num[0].num<<1))
		{
			res[tot++]=num[i].pos;
		}
	}
	printf("%lld\n",tot);
	for(register int i=0;i<tot;i++)
	{
		printf("%lld ",res[i]);
	}
}