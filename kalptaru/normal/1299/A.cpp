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
		cin>>n;
		ll a[n];
		ll b;
		int j;
		vector<int> bit[35];
		FOR(i,0,n)
		{
			cin>>a[i];
			b=a[i];
			j=0;
			while(b>0)
			{
				if(b%2)
				{
					bit[j].pb(i);
				}
				j++;
				b/=2;
			}
		}
		int v=0;
		FOR(i,0,35)
		{
//			cout<<bit[i].size()<<' ';
			if(bit[35-i-1].size()==1)
			{
				v=bit[35-i-1][0];
				break;
			}
		}
		cout<<a[v];
		FOR(i,0,n)
		{
			if(i!=v)
			{
				cout<<' '<<a[i];
			}
		}
	}
	return 0;
}