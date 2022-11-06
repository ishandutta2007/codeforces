#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int x[7],y[7];
		FOR(i,1,7)
		{
			cin>>x[i]>>y[i];
		}
		bool ans=1,x1=0,x2=0,y1=0,y2=0;
		if(x[3]<=x[1] && x[4]>=x[2])
		x1=1;
		if(x[5]<=x[1] && x[6]>=x[2])
		x2=1;
		if(y[3]<=y[1] && y[4]>=y[2])
		y1=1;
		if(y[5]<=y[1] && y[6]>=y[2])
		y2=1;
		if((x1 && y1)||(x2 && y2))
		ans=0;
		if(x1 && x2 && min(y[3],y[5])<=y[1] && max(y[4],y[6])>=y[2] && max(y[3],y[5])<=min(y[4],y[6]))
		ans=0;
		if(y1 && y2 && min(x[3],x[5])<=x[1] && max(x[4],x[6])>=x[2] && max(x[3],x[5])<=min(x[4],x[6]))
		ans=0;
		if(ans)
		cout<<"YES";
		else
		cout<<"NO";
	}
	return 0;
}