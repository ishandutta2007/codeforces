#include<conio.h>
#include<iostream>
using namespace std;
int main()
{
	int b[1001]={0},c,x,n,a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		b[a]++;
	}
	c=b[0];
	for(int i=0;i<1001;i++)
	{
		if(c<b[i])
			c=b[i];
	}
	if(c>((n+1)/2))
		cout<<"NO";
	else
		cout<<"YES";
}