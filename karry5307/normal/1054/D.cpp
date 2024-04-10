#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll cnt,kk,x,limit,prv,cur,curr;
li res;
unordered_map<ll,ll>mp;
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
	cnt=read(),kk=read(),limit=(1<<kk)-1,mp[0]=1;
	for(register int i=1;i<=cnt;i++)
	{
		x=read(),cur=prv^x,curr=cur^limit;
		mp[cur]<mp[curr]?res+=(mp[(prv=cur)]++):res+=(mp[(prv=curr)]++);
	}
	printf("%lld\n",(li)cnt*(cnt+1)/2-res);
}