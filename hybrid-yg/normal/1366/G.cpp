#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,i,dp[N],s[N],j,k;
int r[N],pre[N][N],top,t[N];
char c[N],a[N];
int main()
{
	scanf("%s",c+2);
	scanf("%s",a+2);
	c[1]=a[1]='#';
	m=strlen(a+1)+1;
	n=strlen(c+1)+1;
	c[n]=a[m]='%';
	reverse(c+1,c+1+n);
	reverse(a+1,a+1+m);
	int tot=0;
	for(i=1;i<=n;++i)
	{
		s[i]=s[i-1];
		if(c[i]=='.')
		{
			++s[i];
			++tot;
		}
		else
			--s[i];
	}
	for(i=1;i<=n;++i)
	{
		int s=0;
		for(j=i+1;j<=n;++j)
			if(c[j]=='.')
				++s;
			else
			{
				--s;
				if(s<0)
					break;
			}
		r[i]=min(j,n);
	}
	memset(dp,0x7f,sizeof(dp));
	dp[1]=0;
	for(i=1;i<=m;++i)
		pre[i][0]=1<<30;
	for(i=1;i<=n;++i)
		if(c[i]!='.')
		{
			if(i!=1)
			{
				while(top>0&&t[top]<i)
					--top;
				for(j=m;j>=1;--j)
					dp[j]=pre[j][top]+s[i-1];
			}
			while(top>0&&t[top]<=i)
				--top;
			++top;
			t[top]=r[i];
			for(j=m;j>=1;--j)
			{
				if(c[i]==a[j])
					dp[j]=min(dp[j],dp[j-1]);
				pre[j][top]=min(pre[j][top-1],dp[j]-s[i]);
			}
		}
	cout<<n-(tot-dp[m])*2-m;
}