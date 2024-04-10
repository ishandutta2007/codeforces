#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,N,i,j,a[MAXN];
map<ll,int> x;
ll m,s[MAXN],b[MAXN],ans;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	b[0]=N=1;
	if(m!=1)
	{
		b[N]=m;
		if(m!=-1)for(;b[N]<=100000000000000LL&&b[N]>=-100000000000000LL;N++)b[N+1]=b[N]*m;
		else N++;
	}
	x[0]++;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<N;j++)ans+=x[s[i]-b[j]];
		x[s[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}