using namespace std;
#include<iostream>
int a[5002];
int main()
{
	int n,k=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[a[a[i]]]==i)
			k=1;
	}
	if(k==1)
		cout<<"YES";
	else
		cout<<"NO";
		
}