#include<iostream>
using namespace std;
int a[100000],b[100000];
int k[100000];
int main(){
	int n,x,sum=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[x-1]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		x=x-1;
		b[i]=x;
	}
	k[n-1]=a[b[n-1]];
	for(int i=n-2;i>=0;i--)
	{
		k[i]=min(k[i+1],a[b[i]]);
	}
	//for(int i=0;i<n;i++)
	//	cout<<k[i]<<" ";
	//cout<<endl;
	for(int i=0;i<n-1;i++)
	{
		//cout<<a[b[i]]<<" "<<k[i+1]<<endl;
		if(a[b[i]]>k[i+1])
			sum++;
	}
	cout<<sum;
}