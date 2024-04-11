#include<iostream>
using namespace std;
int gerd(int x,int y)
{
	int t=x/y;
	if(x%y>0)
		return t+1;
	return t; 
}
int main()
{
	int q;
	cin>>q;
	for(int i=0;i<q;i++)
	{
		int n;
		cin>>n;
		int k=0;
		for(int j=0;j<n;j++)
		{
			int l;
			cin>>l;
			k+=l;
		}
		cout<<gerd(k,n)<<endl;
		}
}