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
		string s;
		cin>>s;
		int n=s.size();
		int ans=0;
		int p=0,cnt=0;
		vector<int> a1,a2;
		FOR(i,0,n-2)
		{
			if(s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')
			{
				ans++;	
				p=2;
				cnt=1;
				a1.pb(i+1);
			}
			else if(s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
			{
				if(p==2 && cnt==2)
				{
					a2.pb(i-1);
					a1.pb(i);
					p=1;	
				}
				else
				{
					a1.pb(i+1);
					ans++;
				}
			}
			else
			{
				cnt++;
			}
		}
		cout<<ans<<'\n';
		int j=0;
		FOR(i,0,a1.size())
		{
			if(j<a2.size() && a1[i]==a2[j])
			{
				j++;
			}
			else
			{
				cout<<a1[i]+1<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}