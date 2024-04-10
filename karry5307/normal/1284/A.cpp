#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt,ccnt,x;
string tg[MAXN],dz[MAXN];
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
	x=read()-1;
	cout<<tg[x%cnt]<<dz[x%ccnt]<<endl;
}
int main()
{
	cnt=read(),ccnt=read();
	for(register int i=0;i<cnt;i++)
	{
		cin>>tg[i]; 
	} 
	for(register int i=0;i<ccnt;i++)
	{
		cin>>dz[i];
	}
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}