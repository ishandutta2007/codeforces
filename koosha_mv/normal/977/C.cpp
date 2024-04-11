#include<iostream>
#include<algorithm>
using namespace std;
int a[200003];
int main()
{
	int n,k,p,j=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if((a[k-1]==a[k]) ||(k==0 && a[0]==1))
		cout<<-1;
	else
	{
		if(k==0)
			cout<<1;
		else
			cout<<a[k-1];
	}
}