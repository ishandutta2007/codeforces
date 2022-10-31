#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		long long x,y,t;
		int n;
		cin>>n>>x>>y;
		x&=1,y&=1;
		for(int i=1;i<=n;i++)
		{
			cin>>t;
			x^=t&1;
		}
		if(x==y)cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	return 0;
}