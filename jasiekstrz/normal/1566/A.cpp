#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
	{
		int n,s;
		cin>>n>>s;
		int x=(n+2)/2;
		cout<<s/x<<"\n";
	}
	return 0;
}