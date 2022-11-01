#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,syk,ccc;
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
	scanf("%s",ch+1),n=strlen(ch+1);
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='b'?ccc=syk:ch[i]=='a'?syk=(syk+ccc+1)%MOD:1;
	}
	printf("%d\n",syk);
}