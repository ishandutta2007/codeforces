#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x7fffffff;
struct Item{
	ll cost,type,id;
	inline bool operator <(const Item &rhs)const
	{
		return this->cost>rhs.cost;
	}
};
Item chair[MAXN],other[MAXN];
ll cnt,ccnt,totc,toto,x,y,minn=inf;
double res;
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
int main()
{
	cnt=read(),ccnt=read();
	for(register int i=0;i<cnt;i++)
	{
		x=read(),y=read();
		y==1?chair[++totc]=(Item){x,y,i}:other[++toto]=(Item){x,y,i};
	}
	sort(chair+1,chair+totc+1);
	if(totc>ccnt-1)
	{
		for(register int i=1;i<ccnt;i++)
		{
			res+=1.0*chair[i].cost/2;
		}
		for(register int i=1;i<=toto;i++)
		{
			res+=other[i].cost,minn=Min(minn,other[i].cost);
		}
		for(register int i=ccnt;i<=totc;i++)
		{
			res+=chair[i].cost,minn=Min(minn,chair[i].cost);
		}
		res-=1.0*minn/2;
	}
	else
	{
		for(register int i=1;i<=totc;i++)
		{
			res+=1.0*chair[i].cost/2;
		}
		for(register int i=1;i<=toto;i++)
		{
			res+=other[i].cost;
		}
	}
	printf("%.1lf\n",res);
	if(totc>=ccnt-1)
	{
		for(register int i=1;i<ccnt;i++)
		{
			printf("1 %d\n",chair[i].id+1);
		}
		printf("%d ",totc+toto-ccnt+1);
		for(register int i=ccnt;i<=totc;i++)
		{
			printf("%d ",chair[i].id+1);
		}
		for(register int i=1;i<=toto;i++)
		{
			printf("%d ",other[i].id+1);
		}
	}
	else
	{
		for(register int i=1;i<=totc;i++)
		{
			printf("1 %d\n",chair[i].id+1);
		}
		for(register int i=1;i<=ccnt-totc-1;i++)
		{
			printf("1 %d\n",other[i].id+1);
		}
		printf("%d ",toto-ccnt+totc+1);
		for(register int i=ccnt-totc;i<=toto;i++)
		{
			printf("%d ",other[i].id+1);
		}
	}
	puts("");
}