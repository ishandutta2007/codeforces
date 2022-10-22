#include<iostream>
using namespace std;
long long morabas(long long x1,long long y1,long long x2,long long y2)
{
	if(x1>x2 || y1>y2)
		return 0;
	if((x2-(x1-1))%2==0 || (y2-(y1-1))%2==0)
	{
		return ((x2-(x1-1))*(y2-(y1-1))/2);
	}
	if((x1+y1)%2==0)
	{
		return ((x2-(x1-1))*(y2-(y1-1))+1)/2;
	}
	return ((x2-(x1-1))*(y2-(y1-1))-1)/2;
	
}
long long morabam(long long x1,long long y1,long long x2,long long y2)
{
	if(x1>x2 || y1>y2)
		return 0;
	if((x2-(x1-1))%2==0 || (y2-(y1-1))%2==0)
	{
		return (x2-(x1-1))*(y2-(y1-1))/2;
	}
	if((x1+y1)%2==0)
	{
		return ((x2-(x1-1))*(y2-(y1-1))-1)/2;
	}
	return ((x2-(x1-1))*(y2-(y1-1))+1)/2;
	
}
int main()
{
	long long t,b;
	cin >> t ;
	long long sefid,siah;
	for(int i=0;i<t;i++)
	{
		long long n,m,x1,x2,x3,x4,y1,y2,y3,y4;
		cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		if((n*m)%2==1)
		{
			sefid=((n*m)+1)/2;
			siah=((n*m)-1)/2;
		}
		else
		{
			sefid=((n*m))/2;
			siah=((n*m))/2;
		}
		sefid+=morabam(x1,y1,x2,y2);
		siah-=morabam(x1,y1,x2,y2);
		sefid-=morabas(x3,y3,x4,y4);
		siah+=morabas(x3,y3,x4,y4);
		siah+=morabam(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
		sefid-=morabam(max(x1,x3),max(y1,y3),min(x2,x4),min(y2,y4));
		cout << sefid << " " << siah << endl;
	}
}