#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3,n4,l,t=0;
	cin>>n1>>n2>>n3>>n4>>l;
	for(int i=1;i<=l;i++)
	{
		if(i%n1==0 || i%n2==0 || i%n3==0 || i%n4==0 )
			t++;
	}
	cout << t;
}