#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e6+51;
stack<ll>st;
ll cnt,ccnt;
ll num[MAXN],x[MAXN],res[MAXN];
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
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	ccnt=read();
	for(register int i=0;i<ccnt;i++)
	{
		x[read()]=1;
	}
	for(register int i=cnt;i;i--)
	{
		(st.empty()||num[i]!=st.top()||x[i])?res[i]=1,st.push(num[i]):st.pop();
	}
	if(!st.empty())
	{
		return puts("NO"),0;
	}
	puts("YES");
	for(register int i=1;i<=cnt;i++)
	{
		printf("%d ",res[i]?-num[i]:num[i]);
	}
}