#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51,MOD=853071391,BASE=20050103,INVB=55276785;
ll n,len,lenr,hshr,mx;
ll hsh[MAXN],pw[MAXN],pwInv[MAXN];
char ch[MAXN],s[MAXN];
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
inline ll calcHash(ll l,ll r)
{
	return (li)(hsh[r]-hsh[l-1]+MOD)*pwInv[l-1]%MOD;
}
int main()
{
 	n=read(),scanf("%s",ch+1),len=strlen(ch+1),pw[0]=pwInv[0]=1;
 	for(register int i=1;i<=1000000;i++)
 	{
 		pw[i]=(li)pw[i-1]*BASE%MOD,pwInv[i]=(li)pwInv[i-1]*INVB%MOD;
	}
	for(register int i=1;i<=len;i++)
	{
		hsh[i]=(hsh[i-1]+(li)pw[i]*ch[i])%MOD;
	}
	for(register int i=2;i<=n;i++)
	{
		scanf("%s",s+1),lenr=strlen(s+1),hshr=mx=0;
		for(register int j=1;j<=min(len,lenr);j++)
		{
			hshr=(hshr+(li)pw[j]*s[j])%MOD,hshr==calcHash(len-j+1,len)?mx=j:1;
		}
		for(register int j=mx+1;j<=lenr;j++)
		{
			ch[++len]=s[j],hsh[len]=(hsh[len-1]+(li)pw[len]*s[j])%MOD;
		}
	}
	printf("%s\n",ch+1);
}