#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,t,s=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		s+=t;
	}
	t=0;
	for(int i=1;i<6;i++)
	{
		if((s+i)%(n+1)!=1)
		t+=1;
	}
	cout<<t;
	return 0;
}