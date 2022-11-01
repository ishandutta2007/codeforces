#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,res,w,wt,v;
ll l[MAXN];
char ch[MAXN];
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
		l[i]=read();
	}
	scanf("%s",ch+1);
	for(register int i=1;i<=n;i++)
	{
		if(ch[i]=='L')
		{
			w-=l[i],res+=l[i],w<0?(res-=wt?3*w:5*w),w=0:1;
		}
		if(ch[i]=='W')
		{
			wt=1,w+=l[i],res+=3*l[i];
		}
		if(ch[i]=='G')
		{
			w+=l[i],v+=2*l[i],res+=5*l[i];
		}
		v=min(v,w);
	}
	w?res-=w+v:1,printf("%lld\n",res);
}