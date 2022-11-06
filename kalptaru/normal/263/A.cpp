#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,y,t;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>t;
			if (t==1)
			{
				x=i;
				y=j;
			}
		}
	}
	x=abs(x-2);
	y=abs(y-2);
	cout<<x+y;
	return 0;
}