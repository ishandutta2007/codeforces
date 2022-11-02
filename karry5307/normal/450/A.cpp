#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
ll n,m,res;
queue<pii>q;
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
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		q.push((pii){i,read()});
	}
	while(!q.empty())
	{
		res=q.front().first;
		q.front().second>m?q.push((pii){res,q.front().second-m}):(void)1;
		q.pop();
	}
	printf("%d\n",res);
}