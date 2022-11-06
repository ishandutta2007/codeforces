#include <bits/stdc++.h>
#include <string>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	ll f1=3,f2=2,f3=1,f4=1,f5=0;
	cin>>n;
	if (n==0)
		cout<<"0 0 0";
	else if(n==1)
		cout<<"0 0 1";
	else if(n==2)
		cout<<"0 1 1";
	else
	{
		while(f1!=n)
		{
			f5=f4;
			f4=f3;
			f3=f2;
			f2=f1;
			f1=f2+f3;
		}
		cout<<f2<<' '<<f4<<' '<<f5;
	}
	return 0;
}