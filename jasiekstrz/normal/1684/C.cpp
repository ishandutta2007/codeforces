#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
int t0[N+10];
int t[N+10];
int tab[N+10];
void solve()
{
	int n,m;
	cin>>n>>m;
	bool ok=true;
	vector<pair<int,int>> vec;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>t0[j];
			t[j]=t0[j];
			tab[(i-1)*m+j]=t[j];
		}
		sort(t+1,t+m+1);
		vector<int> diff;
		for(int j=1;j<=m;j++)
		{
			if(t[j]!=t0[j])
				diff.push_back(j);
		}
		if(diff.size()>2)
			ok=false;
		else if(diff.empty())
			vec.emplace_back(0,0);
		else
			vec.emplace_back(diff[0],diff[1]);
	}
	if(!ok)
	{
		cout<<"-1\n";
		return;
	}
	pair<int,int> sw={0,0};
	for(auto v:vec)
	{
		if(v!=make_pair(0,0))
		{
			sw=v;
			break;
		}
	}
	if(sw==make_pair(0,0))
	{
		cout<<"1 1\n";
		return;
	}
	int i=0;
	for(auto v:vec)
	{
		if(v==sw)
		{
			i+=m;
			continue;
		}
		if(v!=make_pair(0,0))
		{
			cout<<"-1\n";
			return;
		}
		if(tab[i+sw.fi]!=tab[i+sw.se])
		{
			cout<<"-1\n";
			return;
		}
		i+=m;
	}
	cout<<sw.fi<<" "<<sw.se<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--)
		solve();
	return 0;
}