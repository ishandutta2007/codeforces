#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5;
int a[N];
int b[N],t[N],nt[N],u;
vector<int>ans[N];int top;

int NT(int x)
{
	while(nt[x]<t[x+1]&&a[nt[x]]==x)++nt[x];
	return nt[x];
}
void dfs(int x)
{
	while(NT(x)<t[x+1])
	{
		int now=nt[x]++;
		dfs(a[now]);
		ans[top].push_back(now);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
#endif
	int n,s;
	cin>>n>>s;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)b[i]=a[i];
	sort(b+1,b+n+1);
	rep(i,1,n)
	if(b[i]!=b[u])
	{
		++u;
		t[u]=i;
		b[u]=b[i];
	}
	t[u+1]=n+1;
	rep(i,1,n)a[i]=lower_bound(b+1,b+u+1,a[i])-b;
	
	rep(i,1,u)nt[i]=t[i];
	rep(i,1,u)
	if(NT(i)<t[i+1])
	{
		++top;
		dfs(i);
		s-=ans[top].size();
		reverse(ans[top].begin(),ans[top].end());
	}
	if(s<0)puts("-1");
	else
	{
		s=min(s,top);
	if(s<2)
	{
		printf("%d\n",top);
	#ifndef kcz
		rep(i,1,top)
		{
			printf("%d\n",(int)ans[i].size());
			for(auto x:ans[i])printf("%d ",x);
			puts("");	
		}
	#endif
	}
	else
	{
		printf("%d\n",top-s+2);
		
		int sum=0;
		rep(i,1,s)sum+=ans[i].size();
		printf("%d\n",sum);
		rep(i,1,s)for(auto x:ans[i])printf("%d ",x);
		puts("");
		
		printf("%d\n",s);
		per(i,s,1)printf("%d ",ans[i][0]);
		puts("");
		
		rep(i,s+1,top)
		{
			printf("%d\n",(int)ans[i].size());
			for(auto x:ans[i])printf("%d ",x);
			puts("");	
		}
	}
	}
}