#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll len,qcnt,l,r;
ll f[MAXN];
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
	scanf("%s",ch+1),len=strlen(ch+1),qcnt=read();
	for(register int i=1;i<=len;i++)
	{
		f[i]=!!(ch[i]==ch[i+1])+f[i-1];
	}
	for(register int i=1;i<=qcnt;i++)
	{
		l=read(),r=read(),printf("%d\n",f[r-1]-f[l-1]);
	}
}