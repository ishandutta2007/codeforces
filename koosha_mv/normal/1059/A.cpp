using namespace std;
#include<iostream>
int main()
{
	int n,l,a,t1,t2,k=0,tt1=0,tt2;
	cin>>n>>l>>a;
	for(int i=0;i<n;i++)
	{
		cin>>t1>>t2;
		k+=int((t1-tt1)/a);
		tt1=t1+t2;
	}
	k+=int((l-tt1)/a);
	cout<<k;
}