#include<bits/stdc++.h>

int n,m,k,p[110],s[110],sp[110];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		sp[s[i]]=std::max(sp[s[i]],p[i]);
	}
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		int x;scanf("%d",&x);
		if(p[x]!=sp[s[x]])ans++;
	}
	printf("%d",ans);
}