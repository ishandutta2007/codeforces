#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int h=3,r=max(n-k,k-1),c=min(n-k,k-1);
	if(c>0)
		cout<<c*4+r*3+3;
	else
		cout<<r*3+3;
}