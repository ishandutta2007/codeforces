#include<bits\stdc++.h>
using namespace std;

long long n;
long long p,q,r,x,w,lst;
long long fa[400002][21],mx[400002][21],sum[400002][21],to[400002][21],cnt;
long long wt[400002];

void add(long long r,long long w)
{
	fa[++cnt][0]=r;
	mx[cnt][0]=w;
	wt[cnt]=w;
	
	long long i;
	
	for (i=1;i<=20;i++) fa[cnt][i]=fa[fa[cnt][i-1]][i-1];
	
	for (i=1;i<=20;i++) mx[cnt][i]=max(mx[cnt][i-1],mx[fa[cnt][i-1]][i-1]);
	
	long long cur=r;
	for (i=20;~i;i--) if (mx[cur][i]<w) cur=fa[cur][i];
	
	if (cur!=cnt&&wt[cur]>=wt[cnt]) to[cnt][0]=cur;
	
	for (i=1;i<=20;i++) to[cnt][i]=to[to[cnt][i-1]][i-1];
	
	sum[cnt][0]=wt[to[cnt][0]];
	for (i=1;i<=20;i++) sum[cnt][i]=sum[cnt][i-1]+sum[to[cnt][i-1]][i-1];
}
int main()
{
	scanf("%I64d",&n);
	
	long long i,j;
	
	add(1,0);
	
	while (n--)
	{
		long long op;
		scanf("%I64d",&op);
		
		if (op==1)
		{
			scanf("%I64d%I64d",&p,&q);
			r=p^lst;w=q^lst;
			//cout<<r<<' '<<w<<endl;
			
			add(r,w);
		}
		
		if (op==2)
		{
			scanf("%I64d%I64d",&p,&q);
			r=p^lst;x=q^lst;
			//cout<<r<<' '<<x<<endl;
			
			lst=0;
			
			if (wt[r]>x)
			{
				printf("%I64d\n",lst);
				continue;
			}
			
			x-=wt[r];
			
			long long cur=r;
			
			for (i=20;~i;i--)
			{
				lst+=(1ll<<i);
				
				if (to[cur][i]==0)// path is too short
				{
					lst-=(1ll<<i);
					continue;
				}
				
				if (sum[cur][i]>x)// sum is too big
				{
					lst-=(1ll<<i);
					continue;
				}
				
				x-=sum[cur][i];
				cur=to[cur][i];
			}
			
			printf("%I64d\n",++lst);
		}
	}
	
	return 0;
}