#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,i,t,k,a[N],b[N],tot,e,j;
struct str{
	int u,v;
};
vector<str> g;
int o(int x,int y)
{
	g.push_back((str){x,y});
}
void dfs(int l,int r)
{
	if(l==r)
		return;
	int mid=l+r>>1;
	dfs(l,mid);
	dfs(mid+1,r);
	for(int i=0;i<=mid-l;++i)
		o(l+i,mid+i+1);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	int m=0,w=1;
	for(i=19;i>=0;--i)
		if((n>>i)&1)
		{
			if(w)
			{
				b[i]=1;
				w=0;
			}
			dfs(m+1,m+(1<<i));
			m+=(1<<i);
		}
	e=w=1;
	for(i=0;i<=19;++i)
	{
		if(b[i])
			break;
			if((n>>i)&1)
			{
				if(w)
				{
					for(j=0;j<(1<<i);++j)
						a[k++]=m--;
					w=0;
				}
				else
				{
					for(j=0;j<(1<<i);++j)
					{
						o(m-j,a[j]);
						a[k++]=m-j;
					}
					m-=(1<<i);
					continue;
				}
			}
		if(!w)
			for(j=k-1;j>=0;--j)
			{
				a[k++]=e;
				o(a[j],e++);
			}
	}
	printf("%d\n",g.size());
	for(auto it:g)
		printf("%d %d\n",it.u,it.v); 
}