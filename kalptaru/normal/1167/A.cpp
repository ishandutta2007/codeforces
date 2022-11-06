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
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool f=0;
		FOR(i,0,n)
		{
			if(s[i]=='8')
			{
				if((i+10)<n)
				{
					f=1;
					break;
				}
			}
		}
		if(f)cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
	return 0;
}