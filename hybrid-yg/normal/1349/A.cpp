#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,a,f[N],j,mn[N],b[N],mnn[N];
long long ans=1;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	memset(mn,0x7f,sizeof(mn));
	memset(mnn,0x7f,sizeof(mnn));
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		for(j=2;j*j<=a;++j)
			if(a%j==0)
			{
				int s=0;
				while(a%j==0)
				{
					a/=j;
					++s;
				}
				++b[j];
				if(mn[j]>s)
				{
					mnn[j]=min(mnn[j],mn[j]);
					mn[j]=s;
				}
				else
					mnn[j]=min(mnn[j],s);
			}
		if(a!=1)
		{
			++b[a];
			if(mn[a]>1)
			{
				mnn[a]=min(mnn[a],mn[a]);
				mn[a]=1;
			}
			else
				mnn[a]=min(mnn[a],1);
		}
	}
	for(i=2;i<=200000;++i)
	{
		if(b[i]==n)
			for(j=0;j<mnn[i];++j)
				ans*=i;
		if(b[i]==n-1)
			for(j=0;j<mn[i];++j)
				ans*=i;
	}
	cout<<ans;
}