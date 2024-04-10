#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e3;
int tab[N+10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++)
		cin>>tab[i];
	for(int bg=1;bg<=n;bg+=2)
	{
		long long s=0,mn=-1;
		for(int i=bg+1;i<=n;i+=2)
		{
			ans+=max(0LL,-(-mn)+min((long long)tab[bg],(long long)tab[i]-s)+1);
			s-=tab[i];
			mn=min(mn,s);
			s+=tab[i+1];
			//cerr<<bg<<" "<<i<<" "<<ans<<"\n";
		}
	}
	cout<<ans<<"\n";
	return 0;
}