#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e6+51;
vector<pii>x,y,res;
ll lenx,leny,swp,sum;
pii bk;
char sx[MAXN],sy[MAXN];
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
inline void insert(vector<pii>&v,pii el)
{
	if(v.empty()||v.back().first!=el.first)
	{
		return (void)v.push_back(el);
	}
	v.back().second+=el.second;
}
inline void calc(ll len)
{
	bk=y.back(),y.pop_back(),sum=0;
	for(register int i=len;i;i--)
	{
		insert(y,x[x.size()-i]),sum+=x[x.size()-i].second;
	}
	for(register int i=len;i;i--)
	{
		x.pop_back();
	}
	res.push_back((pii){sum,bk.second}),insert(x,bk);
}
int main()
{
	scanf("%s%s",sx+1,sy+1),lenx=strlen(sx+1),leny=strlen(sy+1);
	for(register int i=lenx;i;i--)
	{
		insert(x,(pii){sx[i]-'a',1});
	}
	for(register int i=leny;i;i--)
	{
		insert(y,(pii){sy[i]-'a',1});
	}
	x.size()<y.size()?swap(x,y),swp=1:1;
	if(x.back().first==y.back().first)
	{
		if((x.size()-y.size())%4==3)
		{
			calc((x.size()-y.size()+1)/4*2);
		}
		y.push_back((pii){y.back().first^1,0});
		calc((x.size()-y.size()+1)/4*2+1);
	}
	else
	{
		if(x.size()-y.size()>2)
		{
			calc((x.size()-y.size()+1)/4*2+1);
		}
	}
	while(x.size()>1||y.size()>1)
	{
		calc(1);
	}
	printf("%d\n",res.size());
	for(register pii u:res)
	{
		swp?swap(u.first,u.second):(void)(1);
		printf("%d %d\n",u.first,u.second);
	}
}