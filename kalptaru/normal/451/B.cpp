#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,l=0,r,lf,rf;
	cin>>n;
	ll a[n],b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	bool f=1;
	while (l<n)
	{
		if(a[l]!=b[l])
		break;
		l++;
	}
	r=n-1;
	while (n>=0)
	{
		if(a[r]!=b[r])
		break;
		r--;
	}
	lf=l;
	rf=r;
	if(l>r)
	{
		cout<<"yes \n"<<1<<' '<<1;
		return 0;
	}
	while(l<=rf)
	{
		if(a[l]!=b[r])
		{
			f=0;
			break;
		}
		l++;
		r--;
	}
	if(f)
	{
		cout<<"yes \n"<<lf+1<<' '<<rf+1;
	}
	else
	cout<<"no";
	return 0;
}