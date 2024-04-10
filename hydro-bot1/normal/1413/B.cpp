// Hydro submission #6274ca58bda16328ffbaf761@1651821144646
#include<bits/stdc++.h>
using namespace std;
int a[600][600],b[360000];
int main()
{
	int t,m,n,x,i,j,k,l;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n>>m;
		for(j=0;j<n;j++)
		for(k=0;k<m;k++)
		{
		    cin>>a[j][k];
		    b[a[j][k]]=j;
		}
		for(j=0;j<m;j++)
		for(k=0;k<n;k++)
		{
			cin>>x;
			if(j) continue;
			for(l=0;l<m;l++)
			printf("%d ",a[b[x]][l]);
			cout<<endl;
		}
	}
	return 0;
}