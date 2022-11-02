#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
multiset<ll>st;
ll n,m,kk,res;
ll x[MAXN];
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
	n=read(),kk=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();	
	}
	for(register int i=1;i<=m;i++)
	{
		st.insert(x[i]);
	}
	for(register int i=m+1;i<=n+1;i++)
	{
		res+=*st.rbegin()<=kk,st.insert(x[i]),st.erase(st.find(x[i-m]));
	}
	printf("%d\n",res);
}