#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v;
		for(int i=0;i<k;i++)
		{
			int x;
			cin>>x;
			v.push_back(n-x);
		}
		v.push_back(1e9);
		sort(v.begin(),v.end());
		for(int i=0;i<=k;i++)
		{
			if(n<=v[i])
			{
				cout<<i<<endl;
				break;
			}
			n-=v[i];
		}
	}
	return 0;
}