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
//	cin>>t;
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		int arr[n+2][2];
		FOR(i,0,n+2)
		{
			arr[i][0]=0;
			arr[i][1]=0;
		}
		int b=0,r,c;
		FOR(i,0,q)
		{
			cin>>r>>c;
			if(arr[c][r-1]==1)
			{
				FOR(j,c-1,c+2)
				{
					b-=arr[j][2-r];
				}
				arr[c][r-1]=0;
			}
			else
			{
				FOR(j,c-1,c+2)
				{
					b+=arr[j][2-r];
				}
				arr[c][r-1]=1;
			}	
			if(b==0)
			cout<<"YES"<<'\n';
			else
			cout<<"NO"<<'\n';		
		}
	}
	return 0;
}