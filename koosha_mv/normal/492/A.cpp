#include<iostream>
using namespace std;
int main()
{
	int n,k=0;
	cin>>n;
	int i=0;
	while(1)
	{
		i++;
		k+=(i*(i+1))/2;
		if(k>n)
		{
			cout<<i-1;
			break;
		}
	}
}