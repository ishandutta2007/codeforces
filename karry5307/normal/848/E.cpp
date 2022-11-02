#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353; 
ll n;
li res;
ll g[16]={
	998244352,998244349,998244349,998244337,15,998244309,26,998244305,
	998244341,4,998244343,16,998244352,8,4,0
};
ll f[16]={
	0,0,0,24,4,240,204,1316,2988,
	6720,26200,50248,174280,436904,1140888,3436404
};
ll fr[16],gr[16];
li tmp[32];
inline ll read()
{
    register ll num=0;
    register char ch=getchar();
    while(!isdigit(ch))
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num;
}
inline void conv(ll *f,ll *g)
{
	memset(tmp,0,sizeof(tmp));
	for(register int i=0;i<16;i++)
	{
		for(register int j=0;j<16;j++)
		{
			tmp[i+j]+=(li)f[i]*g[j];
		}
	}
	for(register int i=0;i<32;i++)
	{
		tmp[i]%=MOD;
	}
	for(register int i=30;i>=16;i--)
	{
		for(register int j=0;j<=16;j++)
		{
			tmp[i-16+j]=(tmp[i-16+j]+(li)tmp[i]*::g[j])%MOD;
		}
	}
	for(register int i=0;i<16;i++)
	{
		f[i]=tmp[i]%MOD;
	}
}
int main()
{
	n=read(),fr[0]=gr[1]=1;
	while(n)
	{
		n&1?conv(fr,gr):(void)1,conv(gr,gr),n>>=1;
	}
	for(register int i=0;i<16;i++)
	{
		res+=(li)fr[i]*f[i];
	}
	printf("%d\n",res%MOD);
}