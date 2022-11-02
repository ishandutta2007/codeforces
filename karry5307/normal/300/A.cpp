#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll n,x,c,rr;
vector<ll>v[MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read();
		x==0?v[2].push_back(x):(void)1,x>0?v[1].push_back(x):(void)1;
		if(x<0)
		{
			!c?v[0].push_back(x),c=1:(v[1].push_back(x),rr++);
		}
	}	
	if(rr&1)
	{
		sort(v[1].begin(),v[1].end(),greater<ll>());
		v[2].push_back(v[1].back()),v[1].pop_back();
	}
	printf("%d ",v[0].size());
	for(register int i:v[0])
	{
		printf("%d ",i);
	}
	puts("");
	printf("%d ",v[1].size());
	for(register int i:v[1])
	{
		printf("%d ",i);
	}
	puts("");
	printf("%d ",v[2].size());
	for(register int i:v[2])
	{
		printf("%d ",i);
	}
	puts("");
}