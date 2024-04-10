// syksykCCC yyds
#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
ll inv[MAXN]; 
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
	n=read(),inv[1]=1;
	if(n==1||n==4)
	{
		return puts("YES"),puts(n==1?"1":"1\n3\n2\n4"),0;
	}	
	for(register int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			return puts("NO"),0;
		}
	}
	puts("YES\n1");
	for(register int i=2;i<n;i++)
	{
		inv[i]=(li)(n-n/i)*inv[n%i]%n,printf("%d\n",(li)i*inv[i-1]%n);
	}
	printf("%d\n",n);
}