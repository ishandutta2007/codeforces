#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
ll num[1000005];
ll fa[1000005];
ll nxt[1000005];
ll ans[1000005],top;
int fnd(int a){if(fa[a]==a)return a;return fa[a]=fnd(fa[a]);}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);top=0;
		scanf("%d",&num[1]);fa[1]=1;nxt[1]=2;
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&num[i]);
			fa[i]=i;nxt[i]=i+1;
			if(__gcd(num[i],num[i-1])!=1)fa[i-1]=i;
		}
		nxt[n]=1;
		if(__gcd(num[1],num[n])!=1)
		{
			if(fnd(fa[1])==fnd(fa[n]))
			{printf("0\n");continue;}
			fa[n]=1;
		}
		int now=fnd(fa[1]);
		while(now!=nxt[now])
		{
//			cout<<now<<" "<<nxt[now]<<endl;
//			for(int i=1;i<=n;i++)cout<<fa[i]<<"*"<<nxt[i]<<" ";cout<<endl;
			ans[++top]=nxt[now];
			nxt[now]=nxt[nxt[now]];
			if(__gcd(num[now],num[nxt[now]])!=1)
			{
				if(fnd(fa[now])==fnd(fa[nxt[now]]))break;
				fa[now]=nxt[now];
			}
			now=fnd(fa[nxt[now]]);
//			cout<<now<<endl;
//			for(int i=1;i<=n;i++)cout<<fa[i]<<"*"<<nxt[i]<<" ";cout<<endl;
		}
		if(num[now]==1&&now==nxt[now])ans[++top]=now;
		printf("%d ",top);
		for(int i=1;i<=top;i++)
		{
			printf("%d ",ans[i]);
		}printf("\n");
		
	}
	
	
	
	return 0;
}
/*
5
5
5 9 2 10 15
6
1 2 4 2 4 2
2
1 2
1
1
1
2
*/