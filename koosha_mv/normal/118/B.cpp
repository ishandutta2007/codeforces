#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,k,l;
	cin>>n;
	for(int i=0;i<n*2+1;i++)
	{
		for(int j=0;j<n*2+1;j++)
		{
			k=n-(abs((n-i))+abs((n-j)));
			if(k<0)
			{
				if(j<n)
					cout<<" ";
			}
			else
				cout<<k;
			if(k>0 || j<n)
				cout<<" ";	
		}
		cout<<endl;
	}
}