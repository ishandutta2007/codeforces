#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll d,mx,mn;
ll x[4];
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
	x[1]=read(),x[2]=read(),x[3]=read(),cout<<"First"<<endl;
	mx=max(x[1],max(x[2],x[3])),mn=min(x[1],min(x[2],x[3]));
	cout<<mx-mn<<endl,x[read()]+=mx-mn;
	mx=max(x[1],max(x[2],x[3])),mn=min(x[1],min(x[2],x[3]));
	cout<<(d=mx*2-mn-(x[1]+x[2]+x[3]-mx-mn))<<endl,x[read()]+=d;
	mx=max(x[1],max(x[2],x[3])),mn=min(x[1],min(x[2],x[3]));
	cout<<(mx-mn)/2<<endl;
}