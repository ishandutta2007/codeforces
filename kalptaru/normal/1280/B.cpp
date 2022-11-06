#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		string s[r];
		FOR(i,0,r)
		cin>>s[i];
		int ans=0;
		bool ro[r]={0},co[c]={0},m=0;
		FOR(i,0,r)
		{
			FOR(j,0,c)
			{
				if(s[i][j]=='P')
				{
					ans=1;
					ro[i]=1;
					co[j]=1;
				}
				else
				m=1;
			}
		}
		if(ans==0)
		{
			cout<<ans<<'\n';
			continue;
		}
		if(m==0)
		{
			cout<<"MORTAL"<<'\n';
			continue;
		}
		if(ro[0]==0 || ro[r-1]==0 || co[0]==0 || co[c-1]==0)
		{
			cout<<1<<'\n';
			continue;
		}
		bool f=0;
		FOR(i,0,r)
		{
			if(ro[i]==0)
			f=1;
		}
		FOR(i,0,c)
		{
			if(co[i]==0)
			f=1;
		}
		if(f)
		{
			cout<<2<<'\n';
			continue;
		}
		if(s[0][0]=='A' || s[0][c-1]=='A' || s[r-1][0]=='A' || s[r-1][c-1]=='A')
		{
			cout<<2<<'\n';
			continue;
		}
		f=0;
		FOR(i,0,r)
		{
			if(s[i][0]=='A' || s[i][c-1]=='A')
			{
				f=1;
				break;
			}
		}
		FOR(i,0,c)
		{
			if(s[0][i]=='A' || s[r-1][i]=='A')
			{
				f=1;
				break;
			}
		}
		if(f)
		{
			cout<<3<<'\n';
			continue;
		}
		cout<<4<<'\n';
		
	}
	return 0;
}