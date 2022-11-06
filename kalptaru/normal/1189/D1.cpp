#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector <int> tree[n];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		tree[u-1].push_back(v-1);
		tree[v-1].push_back(u-1);
	}
	bool flag=1;
	for(int i=0;i<n;i++)
	{
		if(tree[i].size()==2)
		{
				flag=0;
				break;
			
		}
	}
	if(flag)
	cout<<"YES";
	else
	cout<<"NO";
	return 0;
}