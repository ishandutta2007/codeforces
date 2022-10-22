#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=2e5;
int tab[N+10];
vector<int> g[N+10];
int mt[N+10];
int mt2[N+10];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		g[i].clear();
	for(int i=1;i<=n;i++)
	{
		cin>>tab[i];
		g[tab[i]].push_back(i);
		mt[i]=mt2[i]=0;
	}
	vector<int> fr1,fr2;
	for(int i=1;i<=n;i++)
	{
		if(g[i].empty())
			fr2.push_back(i);
		else
		{
			mt[g[i][0]]=i;
			mt2[i]=g[i][0];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mt[i]==0)
			fr1.push_back(i);
	}
	if(fr1.empty());
	else if(fr1.size()==1)
	{
		if(fr1[0]!=fr2[0])
		{
			mt[fr1[0]]=fr2[0];
			mt2[fr2[0]]=fr1[0];
		}
		else
		{
			int x=fr1[0];
			int y=g[tab[x]][0];
			mt[y]=x;
			mt2[x]=y;
			mt[x]=tab[x];
			mt2[tab[x]]=x;
		}
	}
	else
	{
		vector<int> xd,t1,t2;
		for(int i=1;i<=n;i++)
		{
			if(mt[i]==0 && mt2[i]==0)
				xd.push_back(i);
			else if(mt[i]==0)
				t1.push_back(i);
			else if(mt2[i]==0)
				t2.push_back(i);
		}
		if(xd.size()==1)
		{
			mt[xd[0]]=t2.back();
			mt2[t2.back()]=xd[0];
			t2.pop_back();
			mt2[xd[0]]=t1.back();
			mt[t1.back()]=xd[0];
			t1.pop_back();
		}
		else if(!xd.empty())
		{
			for(size_t i=0;i+1<xd.size();i++)
			{
				mt[xd[i]]=xd[i+1];
				mt2[xd[i+1]]=xd[i];
			}
			mt[xd.back()]=xd[0];
			mt2[xd[0]]=xd.back();
		}
		for(size_t i=0;i<t1.size();i++)
		{
			mt[t1[i]]=t2[i];
			mt2[t2[i]]=t1[i];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(mt[i]==tab[i])
			ans++;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=n;i++)
		cout<<mt[i]<<" \n"[i==n];
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