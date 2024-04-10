#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<pair<int,int>> ans;
	if(n%3==2)
	{
		for(int i=3;i<=n;i+=3)
			ans.emplace_back(i,n-i+1);
		for(int i=1;i<=n;i+=3)
			ans.emplace_back(i,n-i);
	}
	else
	{
		for(int i=2;i<=n;i+=3)
			ans.emplace_back(i,n-i);
		for(int i=1;i<=n;i+=3)
			ans.emplace_back(i,n-i+1);
	}
	cout<<ans.size()<<"\n";
	for(auto [a,b]:ans)
		cout<<a<<" "<<b<<"\n";
	return 0;
}