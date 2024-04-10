#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define ll long long
#define MAXN 1000005
int n,m,i,j,s[MAXN];
ll a[MAXN],d[MAXN],ans,x;
ll gcd(ll x,ll y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
void work()
{
	x=a[(rand()<<15|rand())%n];
	for(i=1,m=0;(ll)i*i<=x;i++)if(x%i==0)
	{
		d[m++]=i;
		d[m++]=x/i;
	}
	sort(d,d+m);
	m=unique(d,d+m)-d;
	fill(s,s+m,0);
	for(i=0;i<n;i++)s[lower_bound(d,d+m,gcd(a[i],x))-d]++;
	for(i=0;i<m;i++)for(j=i+1;j<m;j++)if(d[j]%d[i]==0)s[i]+=s[j];
	for(i=0;i<m;i++)if(s[i]<<1>=n)ans=max(ans,d[i]);
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%I64d",a+i);
	while(clock()<1900)work();
	cout<<ans<<endl;
	return 0;
}