#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll fact[MAXN];
ll cnt,md,res;
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
	cnt=read(),md=read(),fact[0]=fact[1]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%md;
	}
	for(register int i=1;i<=cnt;i++)
	{
		res=(res+(li)(cnt-i+1)*(cnt-i+1)%md*fact[i]%md*fact[cnt-i]%md)%md;
	}
	printf("%d\n",res);
}