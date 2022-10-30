#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
ll test,cnt,tot,l;
li ccnt;
ll zero[MAXN];
char ch[MAXN];
inline li read()
{
    register li num=0,neg=1;
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
	cnt=read(),ccnt=read(),scanf("%s",ch),l=tot=0;
	for(register int i=0;i<cnt;i++)
	{
		if(ch[i]=='0')
		{
			zero[++tot]=i;
		}
	}
	for(register int i=1;i<=tot;i++)
	{
		if(zero[i]-l<=ccnt)
		{
			ccnt-=zero[i]-l,swap(ch[zero[i]],ch[l]),l++;
			continue;
		}
		swap(ch[zero[i]],ch[zero[i]-ccnt]);
		break;
	}
	printf("%s\n",ch);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}