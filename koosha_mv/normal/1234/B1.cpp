#include<iostream>
using namespace std;
int a[100002]={0};
int p(int x,int k)
{
	for(int i=0;i<k;i++)
	{
		if(a[i]==x)
			return 1;
	}
	return 0;
}
int main()
{
	int n,k;
	cin>>n>>k;
	for(int j=0;j<n;j++)
	{
		int t;
		cin>>t;
		if(p(t,k)==0)
		{
			for(int i=k;i>0;i--)
			{
				a[i]=a[i-1];
			}
			a[0]=t;
		}
	}
	int o=0;
	for(int i=0;i<k;i++)
	{
		if(a[i]!=0)
			o++;
		else
			break;
	}
	cout<<o<<endl;
	for(int i=0;i<k;i++)
	{
		if(a[i]!=0)
			cout<<a[i]<<" ";
		else
			break;
	}
}