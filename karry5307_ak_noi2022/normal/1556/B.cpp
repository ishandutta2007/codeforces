#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int n,o,e;
int a[200000],po[200000],pe[200000];

long long calc()
{
	long long ans=0;int O=0,E=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&1){O++;ans+=abs(i-po[O]);}
		else{E++;ans+=abs(i-pe[E]);}
	}
	return ans;
}

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		o=0,e=0;for(int i=1;i<=n;i++){scanf("%d",&a[i]);if(a[i]&1)o++;else e++;}
		if(abs(o-e)>1){puts("-1");continue;}
		if(n&1)
		{
			if(o>e)for(int i=1;i<=o;i++)po[i]=2*i-1,pe[i]=2*i;else for(int i=1;i<=e;i++)pe[i]=2*i-1,po[i]=2*i;
			printf("%lld\n",calc()/2);
		}
		else
		{
			for(int i=1;i<=o;i++)po[i]=2*i-1,pe[i]=2*i;
			long long ans=calc();
			for(int i=1;i<=o;i++)po[i]=2*i,pe[i]=2*i-1;
			ans=min(ans,calc());
			printf("%lld\n",ans/2);
		}
	}
}