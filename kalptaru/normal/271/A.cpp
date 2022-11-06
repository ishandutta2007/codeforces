#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y,c=1,f;
	cin>>y;
	int d[10],di;
	while(c)
	{
		for(int i=0;i<10;i++)
		d[i]=0;
		c=0;
		y++;
		for(int j=0;j<4;j++)
		{
			f=pow(10,j);
			di=((y-(y%f))/f)%(10);
			if(d[di]==1)
			{
				c=1;
			}
			else
			{
				d[di]=1;
			}		
		}
	}
	cout<<y;
	return 0;
}