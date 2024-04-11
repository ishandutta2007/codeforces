#include<iostream>
using namespace std;
int a[100001];
int main()
{
	int n,plo=0,m=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>plo;
		if (plo<0)
		{
			a[i]=(plo*-1)-1;
			m=max(m,(plo*-1)-1);
		}
		else
		{
			a[i]=plo;
			m=max(m,plo);
		}
		//cout<<m<<endl;
	}
	int t;
	if(n%2==0)
		t=0;
	else
		t=1;
	for(int i=0;i<n;i++)
	{
		if(t==1 && a[i]==m)
		{
			t=0;
			cout<<a[i]<<" ";
		}
		else
			cout<<a[i]*-1-1<<" ";
	}
	
	
}