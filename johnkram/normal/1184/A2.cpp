#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int p[MAXN],phi[MAXN],n,m,i,j,ans;
bool b[MAXN],s[MAXN],t[MAXN];
char c[MAXN];
void check(int x)
{
	fill(t,t+x,0);
	for(j=0;j<n;j++)t[j%x]^=s[j];
	for(j=0;j<x;j++)if(t[j])return;
	ans+=phi[n/x];
}
int main()
{
	scanf("%d%s",&n,c);
	for(i=0;i<n;i++)s[i]=c[i]^'0';
	for(phi[1]=1,i=2;i<=n;i++)
	{
		if(!b[i])phi[p[m++]=i]=i-1;
		for(j=0;j<m&&i*p[j]<=n;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j])phi[i*p[j]]=phi[i]*phi[p[j]];
			else
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
		}
	}
	for(i=1;i*i<=n;i++)if(n%i==0)
	{
		check(i);
		if(i*i<n)check(n/i);
	}
	cout<<ans<<endl;
	return 0;
}