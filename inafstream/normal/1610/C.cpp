#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m;
int a[200005],b[200005];

bool check(int x)
{
	int i,s=0;
	rep(i,n)
	{
		if(b[i]<x-s-1) continue;
		if(a[i]<s) continue;
		s++;
	}
	return s>=x;
}

void solve()
{
	int i;
	scanf("%d",&n);
	rep(i,n) scanf("%d%d",&b[i],&a[i]);
	
	int ans=0,l=1,r=n+1,mid;
	while(l<r)
	{
		mid=(l+r)/2;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid;
	}
	
	cout<<ans<<endl;
}
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve(); 
	}
	return 0;
}