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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		int a[n+1];
		int p=0;
		vector<int> ar;
		FOR(i,0,n)
		{
			cin>>a[i+1];
			if(a[i+1]!=p)
			{
				ar.pb(i+1);
				p=a[i+1];
			}
		}
		int l,r,x;
//		FOR(i,0,ar.size())
//		{
//			cout<<ar[i]<<' ';
//		}
//		cout<<'\n';
		FOR(i,0,m)
		{
			cin>>l>>r>>x;
			int lq;
			lq=lower_bound(ar.begin(),ar.end(),l)-ar.begin();
//			cout<<lq<<'/';
			if(lq==ar.size())
			{
				if(a[l]==x)
				{cout<<-1;}
				else
				cout<<l;
			}
			else
			{
				if(ar[lq]==l)
				{
					if(a[l]!=x)
					{cout<<l;}
					else if(lq+1<ar.size())
					{
						if(ar[lq+1]<=r)
						cout<<ar[lq+1];
						else
						cout<<-1;
					}
					else
					cout<<-1;
				}
				else
				{
					if(a[l]!=x)
					{
						cout<<l;
					}
					else if(ar[lq]<=r)
					{
						cout<<ar[lq];
					}
					else
					{
						cout<<-1;
					}
				}
			}
			cout<<'\n';
		}
	}
	return 0;
}