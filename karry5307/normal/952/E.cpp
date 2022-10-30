#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,x,y;
char s[51],t[51];
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
		scanf("%s%s",s+1,t+1),t[1]=='s'?x++:y++;
	}
	for(register int i=1;i<=20;i++)
	{
		if((i*i/2>=x&&(i*i+1)/2>=y)||(i*i/2>=y&&(i*i+1)/2>=x))
		{
			return printf("%d\n",i),0;
		}	
	}
}