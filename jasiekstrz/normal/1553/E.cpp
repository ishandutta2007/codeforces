#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=3e5;
int tab[N+10];
bool ok(vector<int> &t,int n,int m)
{
	vector<int> g(n+1);
	for(int i=1;i<=n;i++)
		g[t[i]]=i;
	//for(int i=1;i<=n;i++)
	//	cerr<<t[i]<<" \n"[i==n];
	for(int i=1;i<=n;i++)
	{
		//for(int i=1;i<=n;i++)
		//	cerr<<t[i]<<" \n"[i==n];
		//for(int i=1;i<=n;i++)
		//	cerr<<g[i]<<" \n"[i==n];
		//cerr<<"\n";
		if(t[i]==tab[i])
			continue;
		m--;
		int gtab=g[tab[i]];
		int gt=i;
		g[t[i]]=gtab;
		g[tab[i]]=gt;
		swap(t[gt],t[gtab]);
	}
	//cerr<<m<<"\n";
	return (m>=0);
}
void solve()
{
	int n,m;
	cin>>n>>m;
	map<int,int> sh;
	for(int i=1;i<=n;i++)
	{
		cin>>tab[i];
		int s=(i-tab[i]+n)%n;
		if(sh.find(s)==sh.end())
			sh[s]=0;
		sh[s]++;
	}
	vector<int> ans;
	for(auto [s,siz]:sh)
	{
		if(siz<n-2*m)
			continue;
		vector<int> tmp(n+1);
		for(int i=1;i<=n;i++)
			tmp[i]=(i-s+n-1)%n+1;
		if(ok(tmp,n,m))
			ans.push_back(s);
	}
	cout<<ans.size()<<" ";
	for(auto v:ans)
		cout<<v<<" ";
	cout<<"\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int qq;
	cin>>qq;
	while(qq--)
		solve();
	return 0;
}