#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,a[N],f[N],j,k,t;
long long ans=1;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		bool f1,f2;
		f1=f2=false;
		for(i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			f[i]=f[i-1]+(a[i]>=k?1:-1);
			if(f[i]>=1&&i!=1)
				f1=true;
			if(a[i]==k)
				f2=true;
			f[i]=max(f[i],(a[i]>=k?1:-1));
		}
		if(f2&&(f1||n==1))
			puts("yes");
		else
			puts("no");
	}
}