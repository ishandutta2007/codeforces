#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
#define P 1000000007
int m,i,j,p[MAXN],a[MAXN];
bool b[MAXN];
ll n,k,N;
int main()
{
	for(a[1]=1,i=2;i<MAXN;i++)
	{
		if(!b[i])a[p[m++]=i]=i-1;
		for(j=0;j<m&&i*p[j]<MAXN;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j]==0)
			{
				a[i*p[j]]=a[i]*p[j];
				break;
			}
			else a[i*p[j]]=a[i]*(p[j]-1);
		}
	}
	cin>>n>>k;
	for(k=k+1>>1;n>1&&k;k--)if(n<MAXN)n=a[n];
	else
	{
		for(N=n,i=0;i<m&&(ll)p[i]*p[i]<=N;i++)if(N%p[i]==0)
		{
			n=n/p[i]*(p[i]-1);
			while(N%p[i]==0)N/=p[i];
		}
		if(N>1)n=n/N*(N-1);
	}
	cout<<n%P<<endl;
	return 0;
}