#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n,x,y;
	cin>>n>>x>>y;
	if(n-min(x,y)<max(x,y)-1)
		cout<<"Black";
	else
		cout<<"White";
	return 0;
}