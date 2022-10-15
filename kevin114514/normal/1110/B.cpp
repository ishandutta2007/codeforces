#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> lens;
int main()
{
	int n,m,k,last,ans=0;
	cin>>n>>m>>k>>last;
	for(int i=1;i<n;i++)
	{
		int x;
		cin>>x;
		lens.push_back(x-last-1);
		last=x;
	}
	ans+=n;
	sort(lens.begin(),lens.end());
	for(int i=0;i<n-k;i++)
		ans+=lens[i];
	cout<<ans<<endl;
	return 0;
}