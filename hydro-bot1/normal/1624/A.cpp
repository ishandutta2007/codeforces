// Hydro submission #61e1634e8398e2687959b800@1642160975202
#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
	int n,i,j,max=0,min=1e9,t,re;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		max=0;
		min=1e9;
		cin>>t;
		for(j=1;j<=t;j++)
			cin>>a[j];
		for(j=1;j<=t;j++)
		{
			if(a[j]>max)
				max=a[j];
		}
		for(j=1;j<=t;j++)
		{
			if(a[j]<min)
				min=a[j];
		}
		re=max-min;
		cout<<re<<endl;
	}
	return 0;
}