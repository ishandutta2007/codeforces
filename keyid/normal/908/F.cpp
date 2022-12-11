#include <bits/stdc++.h>
using namespace std;

const int MAXN=300005;

int p[MAXN];
char s[MAXN];

int main()
{
	int n;
	scanf("%d",&n);
	char C[5];
	bool flag=false;
	for (int i=0;i<n;i++)
	{
		scanf("%d%s",&p[i],C);
		s[i]=C[0];
		if (s[i]=='G')
			flag=true;
	}
	int ans=0;
	if (flag)
	{
		for (int i=0;i<n;i++)
			if (s[i]=='G')
			{
				int last=i;
				for (int j=i-1;j>=0;j--)
					if (s[j]=='R')
					{
						ans+=p[last]-p[j];
						last=j;
					}
				last=i;
				for (int j=i-1;j>=0;j--)
					if (s[j]=='B')
					{
						ans+=p[last]-p[j];
						last=j;
					}
				break;
			}
		for (int i=n-1;i>=0;i--)
			if (s[i]=='G')
			{
				int last=i;
				for (int j=i+1;j<n;j++)
					if (s[j]=='R')
					{
						ans+=p[j]-p[last];
						last=j;
					}
				last=i;
				for (int j=i+1;j<n;j++)
					if (s[j]=='B')
					{
						ans+=p[j]-p[last];
						last=j;
					}
				break;
			}
		for (int i=0;i+1<n;i++)
			if (s[i]=='G')
			{
				int j;
				for (j=i+1;j<n&&s[j]!='G';j++);
				if (j>=n)
					break;
				int mx[2],last=i;
				memset(mx,0,sizeof(mx));
				for (int k=i+1;k<j;k++)
					if (s[k]=='R')
					{
						ans+=p[k]-p[last];
						mx[0]=max(mx[0],p[k]-p[last]);
						last=k;
					}
				ans+=p[j]-p[last];
				mx[0]=max(mx[0],p[j]-p[last]);
				last=i;
				for (int k=i+1;k<j;k++)
					if (s[k]=='B')
					{
						ans+=p[k]-p[last];
						mx[1]=max(mx[1],p[k]-p[last]);
						last=k;
					}
				ans+=p[j]-p[last];
				mx[1]=max(mx[1],p[j]-p[last]);
				if (p[j]-p[i]<mx[0]+mx[1])
					ans+=p[j]-p[i]-mx[0]-mx[1];
				i=j-1;
			}
	}
	else
	{
		for (int i=0;i<n;i++)
			if (s[i]=='R')
			{
				for (int j=n-1;j>=0;j--)
					if (s[j]=='R')
					{
						ans+=p[j]-p[i];
						break;
					}
				break;
			}
		for (int i=0;i<n;i++)
			if (s[i]=='B')
			{
				for (int j=n-1;j>=0;j--)
					if (s[j]=='B')
					{
						ans+=p[j]-p[i];
						break;
					}
				break;
			}
	}
	printf("%d",ans);
	return 0;
}