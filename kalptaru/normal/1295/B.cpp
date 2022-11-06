#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
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
	int t=1;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		string s;
		cin>>s;
		int dif[2*n+1]={0};
		int d=0;
		FOR(i,0,n)
		{
			dif[d+n]++;
			if(s[i]=='0')
			{
				d++;
			}
			else
			{
				d--;
			}
		}
		ll ans=0;
		if(d<0)
		{
			FOR(i,0,2*n+1)
			{
				if((x-i+n)<=0)
				{
					if(((-1*(x-i+n))%(-1*d))==0)
					{
						ans+=dif[i];
					}
				}
			}
		}
		else if(d>0)
		{
			FOR(i,0,2*n+1)
			{
				if((x-i+n)>=0)
				{
					if(((x-i+n)%d)==0)
					{
						ans+=dif[i];
//						cout<<dif[i]<<' '<<i-n<<'\n';
					}
				}
			}
		}
		else
		{
			if(abs(x)<=n && dif[x+n]!=0)
			{
				ans=(-1);
			}
			else
			ans=0;
		}
		cout<<ans<<'\n';
//		cout<<"----------"<<'\n';
	}
	return 0;
}