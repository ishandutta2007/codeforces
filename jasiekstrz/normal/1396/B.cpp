#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,s,mx,i;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=mx=0;
		for(i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			s+=a;
			mx=max(mx,a);
		}
		if(2*mx>s)
			cout<<"T\n";
		else
			cout<<(s%2==1 ? "T":"HL")<<"\n";
	}
	return 0;
}