#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
bool che(pair<int ,ll> a,pair<int ,ll> b)
{
	if(a.first==b.first)
	return a.second>b.second;
	return a.first<b.first;
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		pair<int ,ll> d[n];
		FOR(i,0,n)
		{
			cin>>d[i].first>>d[i].second;
		}
		sort(d,d+n,che);
		ll p=0,cnt=0;
		multiset<int> a;
		for(int i=n-1;i>=0;i--)
		{
			if((d[i].first-i)>cnt)
			{
				p+=*a.begin();
				a.erase(a.begin());
				i++;
				cnt++;
			}
			else
			{
				a.insert(d[i].second);
			}
//			cout<<'k';
		}
		cout<<p<<'\n';
	}
	return 0;
}