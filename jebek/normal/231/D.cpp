#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int x,y,z,x1,y1,z1,a=0,c,a1,a2,a3,a4,a5,a6;
	cin>>x;
	cin>>y;
	cin>>z;
	cin>>x1;
	cin>>y1;
	cin>>z1;
	cin>>a1;
	cin>>a2;
	cin>>a3;
	cin>>a4;
	cin>>a5;
	cin>>a6;
	if(x<0)
		a=a+a5;
	if(y<0)
		a=a+a1;
	if(z<0)
		a=a+a3;
	if(x1<x)
		a=a+a6;
	if(y1<y)
		a=a+a2;
	if(z1<z)
		a=a+a4;
	cout << a;
	cin >> c;
}