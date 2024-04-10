#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		cout<<a+b+c<<" "<<b+c<<" "<<c<<"\n";
	}
	return 0;
}