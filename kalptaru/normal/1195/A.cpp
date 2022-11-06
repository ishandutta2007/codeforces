#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k,t;
	cin>>n>>k;
	int a[k]={0};
	for(int i=0;i<n;i++)
	{
		cin>>t;
		a[t-1]+=1;
	}
	bool f=0;
	for(int i=0;i<k;i++)
	{
		if(a[i]%2==1)
		{
			if(f)
			{
				f=0;
				n--;
			}
			else f=1;
		}
	}
	cout<<n;
	return 0;
}