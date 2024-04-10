#include<cstdio>

int a[100000];
int b[100000];
bool no[100001];
bool exist[100001];
bool on[100001];

int main()
{
	char t;
	int i,j=-1,n,m,cnt=0;
	scanf("%d %d\n",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%c %d\n",&t,&b[i]);
		if(t=='+')a[i]=1;
		else a[i]=-1;
	}
	for(i=0;i<m;i++)exist[b[i]]=true;
	for(i=m-1;i>=0;i--)
	{
		if(a[i]==1)
		{
			if(on[b[i]])cnt--;
			on[b[i]]=false;
		}
		else
		{
			if(!on[b[i]])cnt++;
			on[b[i]]=true;
		}
	}	
	if(cnt==1)
	{
		for(j=1;j<=n;j++)if(exist[j]&&on[j])break;
	}
	for(i=0;i<m;i++)
	{
		if(a[i]==1)
		{
			if(!on[b[i]])cnt++;
			on[b[i]]=true;
		}
		else
		{
			if(on[b[i]])cnt--;
			if(cnt)no[b[i]]=true;
			on[b[i]]=false;
		}
		if(cnt==1)
		{
			if(j==-1)
			{
				for(j=1;j<=n;j++)if(exist[j]&&on[j])break;
			}
			else if(j!=n+1&&!on[j])j=n+1;
		}
	}
	for(i=m-1;i>=0;i--)
	{
		if(a[i]==1)
		{
			if(on[b[i]])cnt--;
			if(cnt)no[b[i]]=true;
			on[b[i]]=false;
		}
		else
		{
			if(!on[b[i]])cnt++;
			on[b[i]]=true;
		}
		if(cnt==1)
		{
			if(j==-1)
			{
				for(j=1;j<=n;j++)if(exist[j]&&on[j])break;
			}
			else if(j!=n+1&&!on[j])j=n+1;
		}
	}
	if(j==-1)
	{
		cnt=0;
		for(i=1;i<=n;i++)if(!exist[i]||!no[i])cnt++;
		printf("%d\n",cnt);
		for(i=1;i<=n;i++)if(!exist[i]||!no[i])printf("%d ",i);
	}
	else if(j==n+1)
	{
		cnt=0;
		for(i=1;i<=n;i++)if(!exist[i])cnt++;
		printf("%d\n",cnt);
		for(i=1;i<=n;i++)if(!exist[i])printf("%d ",i);
	}
	else
	{
		cnt=!no[j];
		for(i=1;i<=n;i++)if(!exist[i])cnt++;
		printf("%d\n",cnt);
		for(i=1;i<=n;i++)if(!exist[i]||(i==j&&!no[j]))printf("%d ",i);
	}
}