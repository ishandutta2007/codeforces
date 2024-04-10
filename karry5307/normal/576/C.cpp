#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
struct Point{
	ll x,y,id;
	inline ll operator <(const Point &rhs)const
	{
		return y<rhs.y;
	}
	inline ll operator >(const Point &rhs)const
	{
		return y>rhs.y;
	}
};
vector<Point>v[1051];
ll n,x,y,blockSize=1000;
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),y=read(),v[x/blockSize].push_back({x,y,i});
	}
	for(register int i=0;i<=1000;i++)
	{
		if(i&1)
		{
			sort(v[i].begin(),v[i].end());
		}
		else
		{
			sort(v[i].begin(),v[i].end(),greater<Point>());
		}		
	}
	for(register int i=0;i<=1000;i++)
	{
		for(register Point j:v[i])
		{
			printf("%d ",j.id);
		}
	}
}