// Hydro submission #62b7fe6c1e65e67e47ec789c@1656225389437
#include<bits/stdc++.h>
using namespace std;

int n,m,a[100005],lit[100005],unlit[100005],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[n+1]=m;
	int flag=1;
	for(int i=1;i<=n+1;++i)
	{
		if(flag==1)
			lit[i]=lit[i-1]+a[i]-a[i-1];
		else
		{
			lit[i]=lit[i-1];
			unlit[i-1]=a[i]-a[i-1];
		}
		flag=-flag;
	}
	for(int i=n+1;i>=0;--i)
		unlit[i]=unlit[i+1]+unlit[i];
	ans=lit[n+1];
	flag=-1;
	for(int i=0;i<=n+1;++i)
	{
		if(i!=0 && a[i]!=a[i-1]+1)
		{
			int now_lit=lit[i-1]+unlit[i];
			if(flag==1)
				now_lit+=a[i]-a[i-1]-1;
			else
				now_lit+=1;
			ans=max(ans,now_lit);
		}
		if(i!=n+1 && a[i]!=a[i+1]-1)
		{
			int now_lit=lit[i]+unlit[i+1];
			if(flag==1)
				now_lit+=a[i+1]-a[i]-1;
			else
				now_lit+=1;
			ans=max(ans,now_lit);
		}
		flag=-flag;
	}
	printf("%d",ans);
	return 0;
}