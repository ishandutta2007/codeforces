#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int n,k=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	if(a[n-1]<a[n-2]+a[n-3])
	cout<<"YES \n";
	else
	{cout<<"NO \n";return 0;}
	for(int i=0;i<n-2;i++)
	cout<<a[i]<<' ';
	cout<<a[n-1]<<' ';
	cout<<a[n-2];
	return 0;
}