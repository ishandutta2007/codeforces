#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,syk,ak,ioi,ccc;
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
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1),syk=ak=ioi=0;
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='R'?syk++:ch[i]=='P'?ak++:ioi++;
	}
	ccc=syk>ak?syk>ioi?'P':'R':ioi>ak?'R':'S';
	for(register int i=1;i<=n;i++)
	{
		putchar(ccc);
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}