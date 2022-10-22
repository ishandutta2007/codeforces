#include<iostream>
using namespace std;
int a[52][52],b,c,n,m;
int t(int x,int y,int x1,int y1)
{
	if(x+x1>m || y1+y>n)
		return -1;
	int sh=0;
	for(int i=y;i<y+y1;i++)
	{
		for(int j=x;j<x+x1;j++)
		{
			if(a[i][j]==1)
			{
				sh++;
				//cout<<j<<"  "<<i<<endl;
			}
		}
	}
	return sh;
}
int minn(int x,int y)
{
	if(x==-1)
		return y;
	if(y==-1)
		return x;
	return min(x,y);
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>b>>c;
	int l=-1;
	int u;
	//cout<<t(0,0,3,3)<<endl;
	//cin>>u;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			//cout<<j<<" "<<i<<endl<<t(j,i,b,c)<<endl<<t(j,i,c,b)<<endl;
			l=minn(l,t(j,i,b,c));
			l=minn(l,t(j,i,c,b));
		}
	}
	cout<<l;
}