#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int l=1,r=1e6;
		auto get=[](int x)
		{
			int a=x/3,b=x/3,c=x/3;
			if(x%3>=1)a++;
			if(x%3>=2)b++;
			return 2ll*a*b+2ll*b*c+2ll*c*a;
		};
		while(l<r)
		{
			int mid=(l+r)/2;
			if(get(mid)>=n)r=mid;
			else l=mid+1;
		}
		cout<<l<<"\n";
	}
	
	return 0;
}