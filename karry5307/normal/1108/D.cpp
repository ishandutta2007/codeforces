#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res;
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
	n=read(),scanf("%s",ch+1);
	for(register int i=2;i<=n;i++)
	{
		if(ch[i]==ch[i-1])
		{
			res++;
			if(i==n||ch[i-1]==ch[i+1])
			{
				ch[i]=ch[i-1]=='R'?'G':'R';
				continue;
			}
			ch[i]='R'^'G'^'B'^ch[i-1]^ch[i+1];
		}
	}
	printf("%d\n%s\n",res,ch+1);
}