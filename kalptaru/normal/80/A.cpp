#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a;
	cin>>n>>a;
	bool flag=1;
	while(flag)
	{
		flag=0;
		n++;
		for(int i=2;i<n;i++)
		{
			if(n%i==0)
			{
				flag=1;
				i=n;
			}
		}
	}
	if (n==a)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}