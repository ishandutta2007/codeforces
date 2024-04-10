#include<bits/stdc++.h>
using namespace std;
int solve(int a,int b,int c)
{
	return max(0,max(b,c)-a+1);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		cout<<solve(x,y,z)<<" "<<solve(y,z,x)<<" "<<solve(z,x,y)<<endl;
	}
	return 0;
}