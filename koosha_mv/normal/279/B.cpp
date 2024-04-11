#include<iostream>
using namespace std;
int a[100001];
int main()
{
	int jj=0,n,t,k,sh=0,ta=0,j=0,b=0;
	cin>>n>>t;
	for(int i=0;i<n;i++)
	{
		//cout<<sh<<"  "<<ta<<" "<<j<<endl;
		jj=max(jj,(ta-sh));
		cin>>k;
		a[i]=k;
		if(k+j<=t)
		{
			ta++;
			j+=k;
		}
		else
		{
			j+=k;
			while(j>t)
			{
				//cout<<a[sh]<<endl;
				j-=a[sh];
				sh++;
			}
			ta++;
		}
		//cout<<sh<<"  "<<ta<<" "<<j<<endl;
		jj=max(jj,(ta-sh));
	}
	cout<<jj;
}