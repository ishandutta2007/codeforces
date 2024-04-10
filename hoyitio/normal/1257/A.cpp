#include <bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,a,b;
		cin>>n>>m>>a>>b;
		int cnt = abs(a - b);
		cout<<min(cnt + m , n-1)<<endl;
	}
	return 0;
 }