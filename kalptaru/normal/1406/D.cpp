#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
// ll mod=998244353;
ll INF=1e16;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n],d[n];
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		ll y=0,s=a[0];
		FOR(i,1,n)
		{
			d[i]=(a[i]-a[i-1]);
			if(a[i]>a[i-1])
			{
				y+=(a[i]-a[i-1]);
			}
		}
		if(((s+INF)%2)==1)
		{
			if((y%2)==1)
			{
				cout<<(s+y)/2<<'\n';
			}
			else
			{
				if(s<0)
				{
					cout<<s/2+y/2<<'\n';
				}
				else
				{
					cout<<s/2+y/2+1<<'\n';
				}
			}
		}
		else
		{
			if((y%2)==1)
			{
				cout<<s/2+(y+1)/2<<'\n';
			}
			else
			{
				cout<<(s+y)/2<<'\n';
			}
		}
		int q;
		cin>>q;
		ll l,r,x,z=0;
		FOR(i,0,q)
		{
			cin>>l>>r>>x;
			if(l==1)
			{
				s+=x;
			}
			else
			{
				if(x>0)
				{
					d[l-1]+=x;
					if((d[l-1]-x)<0)
					{
						y+=max(z,d[l-1]);
					}
					else
					{
						y+=x;
					}
				}
				else
				{
					if(d[l-1]>0)
					{
						y-=min(-x,d[l-1]);
					}
					d[l-1]+=x;
				}
			}
			if(r<n)
			{
				x=-1*x;
				if(x>0)
				{
					d[r]+=x;
					if((d[r]-x)<0)
					{
						y+=max(z,d[r]);
					}
					else
					{
						y+=x;
					}
				}
				else
				{
					if(d[r]>0)
					{
						y-=min(-x,d[r]);
					}
					d[r]+=x;
				}
			}
			if(((s+INF)%2)==1)
			{
				if((y%2)==1)
				{
					cout<<(s+y)/2<<'\n';
				}
				else
				{
					if(s<0)
					{
						cout<<s/2+y/2<<'\n';
					}
					else
					{
						cout<<s/2+y/2+1<<'\n';
					}
				}
			}
			else
			{
				if((y%2)==1)
				{
					cout<<s/2+(y+1)/2<<'\n';
				}
				else
				{
					cout<<(s+y)/2<<'\n';
				}
			}
		}
	}
	return 0;
}