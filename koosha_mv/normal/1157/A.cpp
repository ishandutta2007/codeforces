#include<iostream>
using namespace std;
int f(int x)
{
	x++;
	while(x%10==0)
		x=x/10;
	return x;
}
int main()
{
	int n,n1=0;
	cin >> n;
		if(n<2 || n>9)
	{
		n1=1;
	}
	if(n==1)
		cout<<9;
	else
	{
		while(n!=1)
		{
			n=f(n);
			if(n<2 || n>9)
			{
				n1++;
				//cout<<n<<n1<<endl;
			}
		}
		n1+=8;
		cout<<n1;
	}
	
}