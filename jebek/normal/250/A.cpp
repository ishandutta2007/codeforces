#include<iostream>
#include<conio.h>
using namespace std;
int main()
{
	int n=0,a[100]={0},k=0,b=0,c[100]={0},h=0,j=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if (a[i]<0)
			a[i]=-1;
		else
			a[i]=0;
		b=b+a[i];
		if(b==-3)
		{
			b=-1;
			c[k]=i-h;
			k++;
			h=i;
		}
	}
	k++;
	c[k-1]=n;
	for(int i=0;i<k-1;i++)
		c[k-1]=c[k-1]-c[i];
	cout<<k<<endl;
	for(int i=0;i<k;i++)
		cout<<c[i]<<"\t";
	cin>>j;
}