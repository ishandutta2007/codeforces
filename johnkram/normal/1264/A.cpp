#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
int t,n,m,i,j,k,a1,a2,a3,a[MAXN],b[MAXN],s[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1,m=0;i<=n;i++)
		{
			scanf("%d",a+i);
			if(i>1&&a[i]==a[i-1])b[m]++;
			else b[++m]=1;
		}
		n>>=1;
		for(i=1;i<=m;i++)s[i]=s[i-1]+b[i];
		a1=a2=a3=0;
		i=1;
		j=upper_bound(s+1,s+m+1,s[i]<<1)-s;
		k=upper_bound(s+1,s+m+1,n)-s-1;
		if(i<=j&&j<=k&&k<=m&&s[k]-s[j]>s[i])
		{
			a1=i;
			a2=j;
			a3=k;
		}
		printf("%d %d %d\n",s[a1],s[a2]-s[a1],s[a3]-s[a2]);
	}
	return 0;
}