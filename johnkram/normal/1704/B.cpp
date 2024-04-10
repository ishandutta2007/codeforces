#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,m,i,j,k,ans,a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		m<<=1;
		for(i=j=k=1,ans=0;i<=n;i++)
		{
			scanf("%d",a+i);
			if(a[i]>a[j])j=i;
			if(a[i]<a[k])k=i;
			if(a[j]-a[k]>m)
			{
				ans++;
				j=k=i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}