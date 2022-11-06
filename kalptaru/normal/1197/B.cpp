#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	t=1;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],m,l=1,r=1;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==n)m=i;
		}
		bool f=1,g=0;
		for(int i=n-1;i>0;i--)
		{
			g=1;
			if(m+r<n)
			{if(a[m+r]==i){r++;g=0;}}
			if(m-l>=0)
			{if(a[m-l]==i){l++;g=0;}}
			if(g==1)
			{f=0; break;}	
		}
		if(f)
		cout<<"YES";
		else
		cout<<"NO";
	}
}