#include<bits/stdc++.h>
using namespace std;
int x,y,z,vx,vy,vz,num;
int main()
{
	cin>>num;
	for(register int i=0;i<num;i++)
	{
		cin>>x>>y>>z;
		vx+=x;
		vy+=y;
		vz+=z;
	}
	if(vx==0&&vy==0&&vz==0)
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
}