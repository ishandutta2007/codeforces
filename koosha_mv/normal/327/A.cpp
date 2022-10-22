#include<iostream>
using namespace std;
int a[101];
int f(int o)
{
	if(o==1)
		return -1;
	return 1;
}
int main()
{
	int u=0;
	int n,k=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
			u++;
	}
	int t,ba=0,bj[2],br;
	bj[0]=-1;
	bj[1]=-1;
	for(int i=0;i<n;i++)
	{
		t=0;
		for(int j=i;j<n;j++)
		{
			t+=f(a[j]);
			if(t>ba)
			{
				ba=t;
				bj[0]=i;
				bj[1]=j;

			}	
		}
	}
	if(bj[0]==-1)
		cout<<u-1;
	else
	{
		cout<<ba+u;
	}
}