#include<iostream>
using namespace std;
int lol(int x,int y,int m)
{
	if(y>=x)
		return y-x;
	return m+y-x;
}
int main()
{
	int n,m,k,kh=1;
	long long t=0;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>k;
		//cout<<lol(kh,k,m)<<endl;
		t+=lol(kh,k,n);
		kh=k;
	}
	cout<<t;
}