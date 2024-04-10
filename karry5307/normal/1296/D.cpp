#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=5e5+51;
ll cnt,x,y,k,h,r;
ll d[MAXN];
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
	cin>>cnt>>x>>y>>k;
	for(register int i=1;i<=cnt;i++)
	{
		h=read(),r=h%(x+y);
		if(!r)
		{
			d[i]=(y-1)/x+1;
		}
		else
		{
			d[i]=(r-1)/x;
		}
	}
	sort(d+1,d+cnt+1);
	for(register int i=1;i<=cnt;i++)
	{
		d[i]+=d[i-1];
		if(k<d[i])
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<cnt<<endl;
}