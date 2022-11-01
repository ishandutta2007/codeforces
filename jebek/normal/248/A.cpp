#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	unsigned long a=0;
	char x[20000]={0};
	int b[20000]={0},c=0,y=0,z=0,u;
	cin>>a;
	for(int i=0;i<2*a;i++)
	{
		cin>>x[i];
		b[i]=int(x[i]-'0');
		if(i%2==0)
			c=c+b[i];
		else
			y=y+b[i];
	}
	if(c+1>(a+1)/2)
		z=a-c;
	else
		z=c;
	if(y+1>(a+1)/2)
		z=a-y+z;
	else
		z=y+z;
	cout<<z;
	cin>>u;
}