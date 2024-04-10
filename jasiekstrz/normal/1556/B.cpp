#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long INF=1e18L+7;
const int N=1e5;
int tab[N+10];
long long f(int n,int z)
{
	long long ans=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(tab[i]!=z)
			cnt++;
		else
		{
			ans+=cnt;
			if(cnt>0)
				cnt--;
			else
				z=(z+1)%2;
		}
	}
	if(cnt>0)
		return INF;
	return ans;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>tab[i];
		tab[i]%=2;
	}
	long long ans=min(f(n,0),f(n,1));
	cout<<(ans==INF ? -1:ans)<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		solve();
	return 0;
}