#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=1e6+51;
ll n,res;
char s[MAXN],t[MAXN];
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
	n=read(),scanf("%s%s",s+1,t+1);	
	for(register int i=1;i<=n;i++)
	{
		if(s[i]!=t[i])
		{
			res++;
			s[i]==t[i+1]&&t[i]==s[i+1]?swap(t[i],t[i+1]):(void)1; 
		}
	}
	printf("%d\n",res);
}