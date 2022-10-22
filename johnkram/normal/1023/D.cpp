#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],p[200005],i,j,k;
bool b[200005];
set<int> s;
set<int>::iterator it;
bool cmp(int x,int y)
{
	if(a[x]==a[y])return x<y;
	return a[x]<a[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)if(a[i]==m)break;
	if(i>n)
	{
		for(i=1;i<=n;i++)if(!a[i])break;
		if(i<=n)a[i]=m;
		else
		{
			puts("NO");
			return 0;
		}
	}
	for(i=n;i;i--)if(a[i])break;
	for(j=i+1;j<=n;j++)a[j]=a[i];
	for(i=1;i<=n;i++)b[i]=!a[i];
	for(i=1;i<=n;i++)p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)s.insert(i);
	for(i=n;i;i=j)
	{
		if(b[p[i]])
		{
			i=0;
			break;
		}
		for(j=i;j&&a[p[i]]==a[p[j]];j--)s.erase(p[j]);
		for(k=p[j+1];;)
		{
			it=s.lower_bound(p[i]);
			if(it==s.begin())break;
			it--;
			if(!a[*it])
			{
				a[*it]=a[p[i]];
				k=min(k,*it);
				s.erase(it);
			}
			else if(*it<k)break;
			else goto xxx;
		}
	}
	xxx:if(i)puts("NO");
	else
	{
		puts("YES");
		for(i=1;i<=n;i++)printf("%d ",a[i]);
	}
	return 0;
}