#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=5e5+10;
const long long INF=1e18L+7;
map<long long,long long> s0,s1;
int solve()
{
	int n;
	cin>>n;
	long long p=0;
	long long dp=0;
	s0.clear();
	s1.clear();
	s0[0]=0;
	s1[0]=0;
	s1[-INF]=-2*N;
	s1[INF]=N;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		p+=x;
		dp--;
		if(s0.find(p)!=s0.end())
			dp=max(dp,s0[p]);
		auto it=prev(s1.lower_bound(p));
		dp=max(dp,i+it->se);
		s0[p]=dp;
		if(s1.find(p)==s1.end() || s1[p]<dp-i)
			s1[p]=dp-i;
		while(s1.upper_bound(p)->se<dp-i)
			s1.erase(s1.upper_bound(p));
		//cerr<<dp<<"\n";
	}
	return dp;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		cout<<solve()<<"\n";
	return 0;
}