#include<iostream>
using namespace std;
int s[101];
int main()
{
	int n,m;
	cin>>n>>m;
	int j,l;
	j=m;
	if((m==0 && n>1)||m>n*9)
		cout<<"-1 -1";
	else
	{
		for(int i=0;i<n-1;i++)
		{
			l=min(9,j-1);
			if(l==-1)
				l=0;
			s[i]=min(9,j-1);
			j-=min(9,j-1);
		}
		s[n-1]=j;
		for(int i=n-1;i>-1;i--)
		{
			cout <<s[i];
		}
		cout<<" ";
		j=m;
		for(int i=0;i<n;i++)
		{
			cout<<min(9,j);
			j-=min(9,j);
		}
		
	}
}