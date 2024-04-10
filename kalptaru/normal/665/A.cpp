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
	int test=1;
//	cin>>test;
	while(test--)
	{
		int a,ta,b,tb;
		cin>>a>>ta>>b>>tb;
		string s;
		cin>>s;
		int ts;
		ts=((((s[0]-'0')*10)+(s[1]-'0')-5)*60)+(((s[3]-'0')*10)+(s[4]-'0'));
		int tsa=ts+ta;
		int t=0;
		int ans=0;
//		cout<<ts<<' '<<tsa<<' ';
		while(t<1140)
		{
			if((t+tb>ts) && (t<tsa))
			{
				ans++;
//				cout<<t<<' ';
			}
			t+=b;
		}
		cout<<ans;
	}
	return 0;
}