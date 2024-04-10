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
		string s;
		cin>>s;
		int o[27]={0};
		int n=s.size();
		int y=0;
		vector<int> ans;
		vector<int> r;
		FOR(i,0,n)
		{
			o[s[i]-'a']++;
		}
		int cc=0;
		FOR(i,0,n)
		{
			while(o[cc]==0 && cc<26)
			{
				cc++;
				while(y>0)
				{
					if((s[r[y-1]]-'a')>cc)
					break;
					ans.pb(r[y-1]);
					r.pop_back();
					y--;
				}
			}
			if((s[i]-'a')==cc)
			{
				ans.pb(i);
				o[s[i]-'a']--;
			}
			else
			{
				r.pb(i);
				y++;
				o[s[i]-'a']--;
			}
//			cout<<cc<<' ';
		}
		while(y>0)
		{
			ans.pb(r[y-1]);
			y--;
		}
		FOR(i,0,ans.size())
		cout<<s[ans[i]];		
	}
	return 0;
}