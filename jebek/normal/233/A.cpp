#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int a,b;
	cin >> a;
	if (a%2==1)
		cout<<-1;
	else
	{
		for(int i=1;i<a+1;i++)
		{
			if(i%2==0)
				cout<<i-1<<"\t";
			else
				cout<<i+1<<"\t";
		}
	}
	cin >> b;
}