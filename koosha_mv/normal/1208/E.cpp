#include<bits/stdc++.h>
using namespace std;
 
int n,w,l;
long long ans[1000010],a[1000010];
long long maxn,now;
long long Q[1000010],L,R;
 
int main()
{
	int x;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		maxn=1;
		a[1]=a[l+2]=0ll;
		for(int j=2;j<=l+1;j++)
		{
			scanf("%I64d",&a[j]);
			if(a[j]>a[maxn]) maxn=j;
		}
		l+=2;
		ans[maxn]+=a[maxn];
		ans[w+2-l+maxn+1]-=a[maxn];
		if(maxn>1)
		{
			L=R=1;
			for(int j=1;j<maxn;j++)
			{
				while(L<R&&a[Q[R-1]]<a[j]) R--;
				Q[R++]=j;
				if(Q[L]+w+2-l<j) L++;
				ans[j]+=a[Q[L]];
				ans[j+1]-=a[Q[L]];
			}
		}
		if(maxn<w+2)
		{
			L=R=1;
			for(int j=w+2;j>w+2-l+maxn;j--)
			{
				x=l-(w+2-j);
				while(L<R&&a[Q[R-1]]<a[x]) R--;
				Q[R++]=x;
				if(j<Q[L]) L++;
				ans[j]+=a[Q[L]];
				ans[j+1]-=a[Q[L]];
			}
		}
	}
	now=0;
	for(int i=2;i<=w+1;i++)
	{
		now+=ans[i];
		printf("%I64d ",now);
	}
	puts("");
	return 0;
}