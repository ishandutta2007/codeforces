#include<cstdio>
#include<algorithm>

using namespace std;

int a[200];

bool prm[200000];int prm_lst[200000],pcnt;long long phi[200000];

void init_mu(int n)
{
	for(int i=2;i<=n;i++)prm[i]=1;phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(prm[i])prm_lst[++pcnt]=i,phi[i]=i-1;
		for(int j=1;j<=pcnt&&prm_lst[j]*i<=n;j++)
		{
			prm[prm_lst[j]*i]=0;
			if(i%prm_lst[j]==0){phi[i*prm_lst[j]]=phi[i]*prm_lst[j];break;;}
			phi[i*prm_lst[j]]=phi[i]*(prm_lst[j]-1);
		}
	}
}

int main()
{
	init_mu(20000);
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int sum=0;for(int i=1;i<=n;i++)sum+=a[i];
		if(!prm[sum]){printf("%d\n",n);for(int i=1;i<=n;i++)printf("%d ",i);puts("");}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j]&1)
				{
					printf("%d\n",n-1);for(int k=1;k<=n;k++)if(k!=j){printf("%d ",k);}puts("");break;
				}
			}
		}
	}
}