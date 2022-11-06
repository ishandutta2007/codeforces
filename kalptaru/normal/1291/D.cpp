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
ll m1=1000000007;
ll m2=67280421310721;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		string s;
		cin>>s;
		n=s.size();
		int ar[n+1][26];
		FOR(i,0,26)
		ar[0][i]=0;
		FOR(i,1,n+1)
		{
			FOR(j,0,26)
			{
				ar[i][j]=ar[i-1][j];
			}
			ar[i][s[i-1]-'a']++;
		}
		int q;
		cin>>q;
		FOR(i,0,q)
		{
			int l,r;
			cin>>l>>r;
			int c=0;
			if(s[l-1]!=s[r-1] || l==r)
			{
				cout<<"YES"<<'\n';
				continue;
			}
			FOR(j,0,26)
			{
				if((ar[r][j]-ar[l-1][j])>0)
				c++;
				if(c>2)
				{
					break;
				}
			}
			if(c>2)
			{
				cout<<"YES"<<'\n';
			}
			else
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}