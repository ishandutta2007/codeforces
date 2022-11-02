#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,res;
ll syk[MAXN],ccc[MAXN];
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
	n=read(),m=read(),scanf("%s%s",s+1,t+1);
	for(register int i=1;i<=n;i++)
	{
		syk[i]=s[i]=='>';
	}
	for(register int i=1;i<=m;i++)
	{
		ccc[i]=t[i]=='^';
	}
	res=syk[1]==ccc[1]&&syk[1]!=ccc[m]&&syk[n]!=ccc[1]&&syk[n]==ccc[m];
	puts(res?"YES":"NO");
}