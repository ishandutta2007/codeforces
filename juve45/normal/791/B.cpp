#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define DMAX 150009

using namespace std;

int n, a, b, m, nrc, use[DMAX];
vector <int>v[DMAX], c[DMAX];

void dfs(int k)
{
	c[nrc].push_back(k);
	use[k] = 1;
	for(int i=0;i<v[k].size();i++)
		if(!use[v[k][i]])
			dfs(v[k][i]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=1;i<=n;i++)
	{
		if(!use[i])
			dfs(i), nrc++;	
	}

	for(int i=0;i<nrc;i++)
	{
		for(int j=0;j<c[i].size();j++)
		{
			if(v[c[i][j]].size() != c[i].size()-1)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
	return 0;

}