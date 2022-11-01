#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
struct Tuple{
	ll l,u;
	inline bool operator <(const Tuple &rhs)const
	{
		return l==rhs.l?u<rhs.u:l<rhs.l;
	}
};
map<Tuple,ll>mp;
Tuple t;
ll test,l,lx,rx,res;
string str;
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
inline void solve()
{
	t=(Tuple){0,0},res=0x3f3f3f3f,lx=rx=-1;
	mp.clear(),l=read(),cin>>str,mp[t]=-1;
	for(register int i=0;i<l;i++)
	{
		if(str[i]=='L')
		{
			t.l++;
		}
		if(str[i]=='R')
		{
			t.l--;
		}
		if(str[i]=='U')
		{
			t.u++;
		}
		if(str[i]=='D')
		{
			t.u--;
		}
		if(mp.find(t)!=mp.end())
		{
			if(i-mp[t]<res)
			{
				rx=i,lx=mp[t],res=i-mp[t];
			}
		}
		mp[t]=i;
	}
	lx!=-1||rx!=-1?printf("%d %d\n",lx+2,rx+1):puts("-1");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}