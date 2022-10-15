#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		mp[x]=i;
	}
	for(int i=1;i<=n;i++)
		cout<<mp[i]<<" ";
	return 0;
}