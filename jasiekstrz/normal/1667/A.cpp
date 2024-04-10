#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=5e3;
int tab[N+10];
long long solve(int n,int z)
{
	long long ans=0;
	long long lst=0;
	for(int i=z-1;i>=1;i--)
	{
		ans+=(lst+tab[i])/tab[i];
		lst=lst-(lst%tab[i])+tab[i];
	}
	lst=0;
	for(int i=z+1;i<=n;i++)
	{
		ans+=(lst+tab[i])/tab[i];
		lst=lst-(lst%tab[i])+tab[i];
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>tab[i];
	long long ans=solve(n,1);
	for(int i=2;i<=n;i++)
		ans=min(ans,solve(n,i));
	cout<<ans<<"\n";
	return 0;
}