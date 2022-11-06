#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n],b,s=0,k=0,j=0;
	vector <int> d;
	cin>>a[0];
	s=a[0];
	k=a[0];
	b=a[0]/2;
	for(int i=1;i<n;i++)
	{
		cin>>a[i];
			s+=a[i];
	}
	s=s/2;
	if(a[0]>s)
	{cout<<1<<"\n"<<1;return 0;}
	for(int i=1;i<n;i++)
	{
		
		if(a[i]<=b)
		{
			k+=a[i];
			j++;
			d.push_back(i+1);
			if(k>s)
			{
				break;
			}
		}
		
	}
	if(k>s)
	{
		cout<<j+1<<"\n"<<1<<' ';
		for(int i=0;i<d.size();i++)
		cout<<d[i]<<' ';
	}
	else
	cout<<0;
	return 0;
}