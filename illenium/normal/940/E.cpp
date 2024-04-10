#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define ll long long
#define maxn 200005
using namespace std;

int n,c;
ll a[maxn];
ll dp[maxn],sum;
multiset <ll> mul;

int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		dp[i]=dp[i-1]+a[i];
		mul.insert(a[i]);
		if(i>c) {mul.erase(mul.find(a[i-c]));sum-=a[i-c];}
		if(i>=c) {dp[i]=min(dp[i],dp[i-c]+sum-*mul.begin());}
	}
	cout<<dp[n];
	return 0;
}