#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int i=0;
	while((x*y)>=1)
	{
		x--;
		y--;
		i++;
	}
	if(i%2==0)
	{
		cout<<"Malvika";
	}
	else
	{
		cout<<"Akshat";
	}
}