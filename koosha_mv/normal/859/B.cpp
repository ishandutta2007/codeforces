#include<iostream>
using namespace std;
int main()
{
	int n,x,y,t;
	cin >> n;
	for(int i=1;i<n/2+2;i++)
	{
		if((i+1)*(i+1)>n)
		{
			x=i;
			y=i;
			break;
		}
	}
	n=n-(x*y);
	if(n>=x)
	{
		y++;
		n=n-x;
	}
	t=(x+y)*2;
	if(n>0)
		t+=2;
	cout << t;
	
}