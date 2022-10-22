#include<iostream>
using namespace std;
int td=1;
int xx=0,yy=0;
int tt(int x,int y,int x1,int y1)
{
	if(x==y)
	{
		td+=min(x1,y1)-x;
		xx=x1;
		yy=y1;
		return 0;
	}
	if(x<y)
	{
		if(x1>y)
		{
			tt(y-1,y-1,x1,y1);
			return 0;
		}
		if(x1==y)
		{
			td++;
			xx=y;
			yy=y1;
			return 0;
		}
		xx=x1;
		yy=y1;
		return 0;
	}
	else
	{
		if(y1>x)
		{
			tt(x-1,x-1,x1,y1);
			return 0;
		}
		if(x==y1)
		{
			td++;
			yy=x;
			xx=x1;
			return 0;
		}
		xx=x1;
		yy=y1;
		return 0;	
	}
	
}

int main()
{
	int n,x1,y1;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1;
		tt(xx,yy,x1,y1);
	}
	cout<<td;
}