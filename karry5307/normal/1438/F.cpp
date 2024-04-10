#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
map<ll,ll>mp,mp2;
mt19937 mt(2005010320050103);
ll h,u,v,w;
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
inline ll rnd()
{
	return mt()%((1<<h)-1)+1;
}
int main()
{
	h=read();
	for(register int i=0;i<420;i++)
	{
		u=rnd(),v=rnd(),w=rnd();
		while(v==u)
		{
			v=rnd();
		}
		while(w==u||w==v)
		{
			w=rnd();
		}
		cout<<"? "<<u<<" "<<v<<" "<<w<<endl,mp[read()]++;
	}
	for(auto i:mp)
	{
		mp2[i.second]=i.first;
	}
	u=(*(--mp2.end())).second,v=(*(--(--mp2.end()))).second;
	for(register int i=1;i<(1<<h);i++)
	{
		if(i!=u&&i!=v)
		{
			cout<<"? "<<u<<" "<<v<<" "<<i<<endl;
			if(read()==i)
			{
				return cout<<"! "<<i<<endl,0;
			}
		}
	}
}