#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<string>
using namespace std;
const int INF=1000000001,maxn=5002;
int a[maxn];
 
int get(int l,int r)
{
	if (l>r) return 0;
	if (l==r)
	{
		return min(a[l],1); 
	}
	int x=INF,sum=0;
	for (int i=l;i<=r;i++)
		if (x>a[i]) x=a[i];
	for (int i=l;i<=r;i++)
		a[i]-=x;
	int pl=l-1;
	for (int i=l;i<=r;i++)
	{
		if (a[i]==0) 
		{
			sum+=get(pl+1,i-1);
			pl=i;
		}
	}	
	if (pl!=r) sum+=get(pl+1,r);
	return min(sum+x,r-l+1);
}
 
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	int l=0,ans=INF;
	ans=min(get(1,n),n);
	cout<<ans;
}