#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51,MOD=1e9+7;
ll n,x,res;
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
	for(register int i=n;i;i--)
	{
		ch[i]=='a'?res=(res+x)%MOD,x=(x+x)%MOD:x=(x+1)%MOD;
	}	
	printf("%d\n",res);
}