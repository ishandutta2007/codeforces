#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,totc,res;
ll l[MAXN],r[MAXN],len[MAXN];
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
	for(register int i=1;i<=n;i++)
	{
		ch[i]=='G'?(i==1||ch[i-1]=='S'?l[++totc]=i:1),r[totc]=i:1;
	}
	for(register int i=1;i<=totc;i++)
	{
		len[i]=r[i]-l[i]+1;
	}
	if(!totc)
	{
		return puts("0"),0;
	}
	if(totc==1)
	{
		return printf("%d\n",r[1]-l[1]+1),0;
	}
	if(totc==2)
	{
		printf("%d\n",l[2]==r[1]+2?len[1]+len[2]:max(len[1],len[2])+1);
		return 0;
	}
	for(register int i=1;i<totc;i++)
	{
		res=max(res,l[i+1]==r[i]+2?len[i]+len[i+1]+1:len[i]+1);
	}
	printf("%d\n",max(res,len[totc]+1));
}