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
	ll x,a;
	double b;
	while(n--)
	{
		cin>>x;
		if(x==1)
		{
			cout<<"NO \n";
			continue;
		}
		b=pow(x,0.5);
		a=b;
		if(a!=b)
		{
			cout<<"NO \n";
			continue;
		}
		b=pow(a,0.5);
		bool f=1;
		for(int i=2;i<=b;i++)
		{
			if(a%i==0)
			{
				cout<<"NO \n";
				f=0;
				break;
			}
		}
		if(f)
		cout<<"YES \n";
	}
	return 0;
}