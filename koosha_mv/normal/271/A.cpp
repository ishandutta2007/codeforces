#include<iostream>
using namespace std;
int f(int p)
{
	int k1,k2,k3,k4;
	k1=p%10;
	k2=p%100/10;
	k3=p%1000/100;
	k4=p%10000/1000;
	if(k1!=k2 && k1!=k3 && k1!=k4 && k2!=k3 && k2!=k4 && k3!=k4)
		return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	int k=n;
	int o=0;
	while(o==0)
	{
		k++;
		if(f(k)==1)
		{
			cout << k;
			o=1;
		}
	}
}