#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll ans;
int n,m,k,N,p[MAXN],a,s[MAXN],i,j,l,x[100],y[100];
bool b[MAXN];
int Pow(int x,int y)
{
	int s=1;
	while(y--)if((ll)s*x<MAXN)s*=x;
	else return -1;
	return s;
}
int main()
{
	n=316;
	for(i=2;i<=n;i++)
	{
		if(!b[i])p[m++]=i;
		for(j=0;j<m&&i*p[j]<=n;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf("%d",&a);
		for(i=a,j=N=0;j<m&&p[j]*p[j]<=i;j++)if(i%p[j]==0)
		{
			x[N]=p[j];
			y[N]=0;
			for(;i%p[j]==0;i/=p[j])y[N]++;
			y[N]%=k;
			if(y[N])N++;
		}
		if(i>1)
		{
			x[N]=i;
			y[N++]=1;
		}
		for(i=0,l=1;i<N;i++)
		{
			j=Pow(x[i],k-y[i]);
			if(~j&&(ll)l*j<MAXN)l*=j;
			else break;
		}
		if(i==N)ans+=s[l];
		for(i=0,l=1;i<N;i++)l*=Pow(x[i],y[i]);
		s[l]++;
	}
	cout<<ans<<endl;
	return 0;
}