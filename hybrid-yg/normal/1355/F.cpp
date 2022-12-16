#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,j,k,f[1005],ans[1005],p[1005],t,tot,l,u,y;
long long c[1005];
unsigned long long s;
int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif*/
	n=1000;
	for(i=2;i<=800;++i)
		for(j=i*2;j<=800;j+=i)
		 	f[j]=1;
	for(i=2;i<=773;++i)
		if(!f[i])
			p[++k]=i;
	scanf("%d",&t);
	c[++tot]=s;
	while(t--)
	{
		s=1;
		int lim=1000000000;
		l=1;
		int ans=1;
		for(i=1;i<=k&&p[i]*p[i]*p[i]<=lim;++i)
		{
			if(((unsigned long long)s)*p[i]%998244353==((unsigned long long)s)%998244353*p[i]%998244353&&s*p[i]<=1000000000000000000ll)
				s*=p[i];
			else
			{
				cout<<'?'<<' '<<s<<endl;
				fflush(stdout);
				scanf("%d",&y);
				for(j=l;j<=i;++j)
					if(y%p[j]==0)
					{
						long long k=1;
						for(k=p[j];k*p[j]<=1000000000;k*=p[j]);
						cout<<'?'<<' '<<k<<endl;
						fflush(stdout);
						scanf("%d",&u);
						lim/=u;
						k=0;
						while(u!=1)
						{
							++k;
							u/=p[j];
						}
						ans*=(k+1);
					}
				l=i;
				s=p[i];
			}
		}
		if(s!=1)
		{
			cout<<'?'<<' '<<s<<endl;
			fflush(stdout);
			scanf("%d",&y);
			for(j=l;j<=i&&j<=k;++j)
				if(y%p[j]==0)
				{
					long long k=1;
					for(k=p[j];k*p[j]<=1000000000;k*=p[j]);
					cout<<'?'<<' '<<k<<endl;
					fflush(stdout);
					scanf("%d",&u);
					lim/=u;
					k=0;
					while(u!=1)
					{
						++k;
						u/=p[j];
					}
					ans*=(k+1);
				}
		}
		if(ans==1)
		{
			cout<<'!'<<' '<<8<<endl;
		 	fflush(stdout);
		}
		else
		{
			cout<<'!'<<' '<<ans*2<<endl;
		 	fflush(stdout);
		}
	}
}