using namespace std;
#include<iostream>
int a[101]={0};
int main()
{
	int n,p,q;
	cin>>n;
	cin>>p;
	for(int i=0;i<p;i++)
	{
		int k;
		cin>>k;
		a[k]=1;
	}
	cin>>p;
	for(int i=0;i<p;i++)
	{
		int k;
		cin>>k;
		a[k]=1;
	}
	q=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			q=1;
		}
	}
	if(q==0)
		cout<<"I become the guy.";
	else
		cout<<"Oh, my keyboard!";
}