#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 262144
int n,m,N,i,j,k,l,o,p,a[MAXN],ans,u[MAXN],v[MAXN],s,t0[MAXN],t1[MAXN];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)scanf("%d",a+i);
		for(N=1;N<=n;N<<=1);
		fill(t0,t0+N,0);
		fill(t1,t1+N,0);
		sort(a+1,a+n+1);
		s=n;
		for(i=1,l=0;i<=n;i=j)
		{
			for(j=i+1;j<=n&&a[i]==a[j];j++);
			u[++l]=a[i];
			v[l]=j-i;
			for(o=v[l];o<N;o+=o&-o)
			{
				t0[o]++;
				t1[o]+=v[l];
			}
		}
		for(i=0,j=1;;i++)
		{
			for(;j<=n&&a[j]<i;j++);
			if(j>n||a[j]>i)break;
		}
		ans=l-i;
		for(k=1;k<=l&&u[k]<i;k++)
		{
			for(o=v[k];o<N;o+=o&-o)
			{
				t0[o]--;
				t1[o]-=v[k];
			}
			s-=v[k];
		}
		for(j=0;i<n&&k<=l;i++)
		{
			if(u[k]==i)
			{
				for(o=v[k];o<N;o+=o&-o)
				{
					t0[o]--;
					t1[o]-=v[k];
				}
				s-=v[k];
				k++;
			}
			else j++;
			if(j>m)break;
			if(j>=s)
			{
				ans=0;
				break;
			}
			int l1=0,r=N,mid;
			o=p=0;
			while(l1+1<r)
			{
				mid=l1+r>>1;
				if(p+t1[mid]<=m)
				{
					l1=mid;
					o+=t0[mid];
					p+=t1[mid];
				}
				else r=mid;
			}
			o+=(m-p)/r;
			ans=min(ans,l+j-o-i-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}