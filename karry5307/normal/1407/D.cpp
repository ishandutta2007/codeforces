#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=4e5+51;
ll n,tp1,tp2;
ll x[MAXN],f[MAXN],st1[MAXN],st2[MAXN];
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
	n=read(),memset(f,0x3f,sizeof(f)),f[1]=0;
	st1[++tp1]=st2[++tp2]=1,x[1]=read();
	for(register int i=2;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=2;i<=n;i++)
	{
		f[i]=f[i-1]+1;
		while(x[i]>=x[st1[tp1]]&&tp1)
		{
			x[i]!=x[st1[tp1]]?f[i]=min(f[i],f[st1[tp1-1]]+1):1,tp1--;
		}
		while(x[i]<=x[st2[tp2]]&&tp2)
		{
			x[i]!=x[st2[tp2]]?f[i]=min(f[i],f[st2[tp2-1]]+1):1,tp2--;
		}
		st1[++tp1]=i,st2[++tp2]=i;
	}
	printf("%d\n",f[n]);
}