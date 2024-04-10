#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,mx,u,v;
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
	n=read(),mx=1;
	for(register int i=2;i<=n;i++)
	{
		cout<<"? "<<mx<<" "<<i<<endl,u=read();
		cout<<"? "<<i<<" "<<mx<<endl,v=read();
		res[u>v?mx:i]=max(u,v),mx=u>v?i:mx;
	}
	res[mx]=n,cout<<"! ";
	for(register int i=1;i<=n;i++)
	{
		cout<<res[i]<<" ";
	}
}