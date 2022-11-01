#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->y<rhs.y;
	}
};
struct Node{
	ll x[3];
};
Tuple p,r,s;
Node res[MAXN];
priority_queue<Tuple>q;
ll cnt,tot;
ll num[MAXN];
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
		num[i]=read();
	}
	sort(num,num+cnt),p.x=num[0],p.y=1;
	for(register int i=1;i<=cnt;i++)
	{
		if(num[i]!=num[i-1])
		{
			q.push(p),p.x=num[i],p.y=1;
			continue;
		}
		p.y++;
	}
	while(q.size()>=3)
	{
		p=q.top(),q.pop(),r=q.top(),q.pop(),s=q.top(),q.pop();
		p.y--,r.y--,s.y--;
		if(p.y)
		{
			q.push(p);
		}
		if(r.y)
		{
			q.push(r);
		}
		if(s.y)
		{
			q.push(s);
		}
		res[++tot].x[0]=p.x,res[tot].x[1]=r.x,res[tot].x[2]=s.x;
	}
	printf("%d\n",tot);
	for(register int i=1;i<=tot;i++)
	{
		sort(res[i].x,res[i].x+3,greater<ll>());
		printf("%d %d %d\n",res[i].x[0],res[i].x[1],res[i].x[2]);
	}
}