#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,s,p;
	cin>>k>>n>>s>>p;
	cout<<(k*((n-1)/s+1)-1)/p+1;	
}