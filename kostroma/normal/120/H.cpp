#include<iostream>
#include<cstdio>
#include<string>
#include <queue>
#include <vector>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}
#define int li
int n;
string s[300];
vector <pair < int, string > > mal[300];
vector < pair <int, string> > all;
int p=2011;
int m;
vector <int> c[250];
bool used[250];
int mt[250*250];
//int f[250][250*250];
bool try_kuhn (int v) {
	if (used[v])  return false;
	used[v] = true;
	for (int i=0; i<c[v].size(); ++i) 
	{
		int to = c[v][i];
		if (mt[to] == -1 || try_kuhn (mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}
string ans[300];
void solve()
{
	cin>>n;
	for (int i=0; i<n; i++)
	{
		cin>>s[i];
		for ( int mask=1; mask<(1<<s[i].length()); mask++ )
		{
			int z=0;
			string u;
			for (int j=0; j<s[i].length(); j++)
				if ( mask & (1<<j) )
				{
					u+=s[i][j];
					z++;
				}
			if ( z<=4 && z>0)
			{
				int has=0;
				for ( int j=0; j<u.length(); j++ )
					has=has*p+u[j];
				mal[i].pb ( mp (has, u) );
				all.pb ( mp (has, u) );
				//cout<<u<<endl;
			}
		}
	}
	for (int i=0; i<n; i++)
	{
		sort (mal[i].begin(), mal[i].end());
		mal[i].resize( unique (mal[i].begin(), mal[i].end())-mal[i].begin() );
	}
	sort (all.begin(), all.end());
	all.resize( unique (all.begin(), all.end())-all.begin() );
	m=all.size();
	for (int i=0; i<n; i++)
	{
		for ( int j=0; j<mal[i].size(); j++ )
		{
			int cur=mal[i][j].first;
			int l=0, r=m;
			while (l+1<r)
			{
				int mm=l+r; mm/=2;
				if ( all[mm].first>cur )
					r=mm;
				else 
					l=mm;
			}
			if (all[l].first==cur)
				c[i].pb(l);
		}
	}

	memset (mt, -1, sizeof mt);
	for ( int v=0; v<n; v++ )
	{
		memset (used, false, sizeof used);
		try_kuhn(v);
	}
	for ( int i=0; i<m; i++ )
		if (mt[i]!=-1)
		{
			int cur=mt[i];
			ans[cur]=all[i].second;
		}
	bool f=true;
	for ( int i=0; i<n; i++ )
		if (ans[i].length()==0)
		{
			f=false;
			break;
		}
	if (!f)
	{
		cout<<"-1";
		return;
	}
	for (int i=0; i<n; i++)
		cout<<ans[i]<<endl;
}