#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll prefix[MAXN],x[MAXN];
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
	for(register int i=2;i<=n;i++)
	{
		cout<<"? 1 "<<i<<endl,prefix[i]=read();
	}
	for(register int i=3;i<=n;i++)
	{
		x[i]=prefix[i]-prefix[i-1];
	}
	cout<<"? 2 3"<<endl,x[1]=prefix[3]-read(),x[2]=prefix[2]-x[1],cout<<"! ";
	for(register int i=1;i<=n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}