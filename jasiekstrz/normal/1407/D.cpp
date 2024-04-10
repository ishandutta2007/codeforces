#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int tab[300010];
int ans[300010];
vector<int> stck[2]; //0-ros, 1-mal
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>tab[i];
	stck[0].push_back(n);
	stck[1].push_back(n);
	for(i=n-1;i>=1;i--)
	{
		ans[i]=ans[i+1]+1;
		while((!stck[0].empty())&&(tab[stck[0].back()]>tab[i]))
		{
			ans[i]=min(ans[i],ans[stck[0].back()]+1);
			stck[0].pop_back();
		}
		if(!stck[0].empty())
			ans[i]=min(ans[i],ans[stck[0].back()]+1);
		while((!stck[0].empty())&&(tab[stck[0].back()]==tab[i]))
			stck[0].pop_back();
		stck[0].push_back(i);
		while((!stck[1].empty())&&(tab[stck[1].back()]<tab[i]))
		{
			ans[i]=min(ans[i],ans[stck[1].back()]+1);
			stck[1].pop_back();
		}
		if(!stck[1].empty())
			ans[i]=min(ans[i],ans[stck[1].back()]+1);
		while((!stck[1].empty())&&(tab[stck[1].back()]==tab[i]))
			stck[1].pop_back();
		stck[1].push_back(i);
		//cerr<<i<<" "<<x<<" "<<y<<" "<<ans[i]<<"\n";
	}
	cout<<ans[1]<<"\n";
	return 0;
}