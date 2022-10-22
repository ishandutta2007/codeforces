#include<iostream>
using namespace std;
int a[1000001]={0};
int main()
{
	for(int i=0;i<1000001;i++)
		a[i]=0;
	int h,n,k=1,t;
	h=2;
	cin>>n;
	a[1]=1;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		k+=t;
		a[k]=h;
		h++;
	}
	int p,l,o,r;
	cin>>l;
	for(int i=0;i<l;i++)
	{
		
		cin>>o;
		r=o;
		while(a[r]==0)
		{
			r--;
			//cout<<a[r]<<"  "<<r<<endl;
		}
		
		//cout<<endl<<endl<<r<<endl;
		cout<<a[r]<<endl;
	}
	for(int i=0;i<100;i++)
	{
		//cout<<a[i]<<"  "<<i<<endl;
	}
}