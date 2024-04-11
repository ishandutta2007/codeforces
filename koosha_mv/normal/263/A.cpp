#include<iostream>
using namespace std;
int ghadr(int e)
{
	if(e<0)
		e=e*-1;
	return e;
}
int main()
{
	int n,j;
	for(int i=0;i<25;i++)
	{
		cin >> n;
		if(n==1)
			j=i;
	}
	int a1,a2,a3,a4,a5;
	a1=j/5;
	a2=j%5;
	a3=ghadr(a1-2);
	a4=ghadr(a2-2);
	a5=a3+a4;
	cout << a5;
	
}