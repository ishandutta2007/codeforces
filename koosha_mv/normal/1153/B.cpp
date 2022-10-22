#include<iostream>
using namespace std;
int ch[101],r[101];
int k[100][100];
int main()
{
	int n,m,lop;
	cin>>n>>m>>lop;
	for(int i=0;i<m;i++)
		cin>>r[i];
	for(int i=0;i<n;i++)
		cin>>ch[i];
	int t;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>t;
			if(t==1)
				k[i][j]=min(ch[i],r[j]);
			else
				k[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<k[i][j]<<" ";
		}
		cout<<endl;
	}
}