#include<iostream>
using namespace std;
int km(int a,int b)
{
		if (a%10==0)
		{
			a=a/10;
		}
		else
		{
			a=a-1;
		}
		if (b>1)
		{
		return km(a,b-1);	
		}
		return (a);

	return (a);
	
	}
	
int main()
{
	int a,b;
	cin >> a >> b ;
	cout << km(a,b);
	
	return 0;	
}