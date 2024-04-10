#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
int main()
{
	int n,t;
	cin>>n;
	vector<int> v;
	int present = 1;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i<n;i++)
	{
		if(a[i]>=present)
		{
			present++;
		}
	}
	cout<<present;
}