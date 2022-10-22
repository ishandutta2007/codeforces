#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
void solve()
{
	int n;
	cin>>n;
	int ans=0;
	while(n>0)
	{
		ans=max(ans,n%10);
		n/=10;
	}
	cout<<ans<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		solve();
	return 0;
}