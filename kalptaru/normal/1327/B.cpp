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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	
	while(test--)
	{
		int n;
		cin>>n;
		bool pri[n]={0};
		int ap;
		int in=-1;
		FOR(i,0,n)
		{
			int k;
			int p;
			bool f=1;
			cin>>k;
			FOR(j,0,k)
			{
				cin>>p;
//				cout<<p<<'p';
				if(f && pri[p-1]==0)
				{
					pri[p-1]=1;
					f=0;
				}
			}
			if(f)
			{
				in=i;
			}
		}
		if(in==-1)
		{
			cout<<"OPTIMAL"<<'\n';
		}
		else
		{
			cout<< "IMPROVE"<<'\n';
			FOR(i,0,n)
			{
				if(pri[i]==0)
				{
					ap=i;
					break;
				}
			}
			cout<<in+1<<' '<<ap+1<<'\n';
		}
	}
	return 0;
}