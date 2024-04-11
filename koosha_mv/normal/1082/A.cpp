#include<iostream>
#include<algorithm>
using namespace std;
int f(int n,int x,int y,int d)
{
	int a=-1,p=-1;
	if((abs(x-y))%d==0) {
		cout<<abs(x-y)/d<<endl;
		return 0;
	}
	else if((y-1)%d==0 || (n-y)%d==0)
	{
		if((y-1)%d==0)
		{
			a=(y-1)/d;
			if((x-1)%d==0)
				a+=(x-1)/d;
			else
				a+=((x-1)/d)+1;
		}
		if((n-y)%d==0)
		{
			p=(n-y)/d;
			p+=(n-x)/d;
			if((n-x)%d!=0)
				p++;
		}	
	}
	if(a==-1 && p==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
		if(a==-1 || p==-1)
			cout << max(p,a)<<endl;
		else
			cout<<(min(p,a))<<endl;
	}
}
int main()
{
	int k;
	cin>>k;
	int l1,l2,l3,l4;
	for(int i=0;i<k;i++)
	{
		cin>>l1>>l2>>l3>>l4;
		f(l1,l2,l3,l4);
	}
}