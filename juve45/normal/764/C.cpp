#include <bits/stdc++.h>
#define DMAX 100009
#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;

vector <int> v[DMAX];
int n, m, k, ans1 = 1, ans2 = 1, c[DMAX], x, y;

int dfs(int nod, int col, int t)
{
	for(int i=0;i<v[nod].size();i++)
	{
		if(t == v[nod][i]) continue;
		if(c[v[nod][i]] != col) return 0;
		if(dfs(v[nod][i], col, nod) == 0) return 0;
	}
	return 1;
}

int dfs2(int nod)
{
	for(int i=0;i<v[nod].size();i++)
	{
		if(dfs(v[nod][i], c[v[nod][i]], nod) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int dfs1(int nod, int t)
{

	for(int i=0;i<v[nod].size();i++)
	{
		int nw = v[nod][i];
		if(c[nw] != c[nod])
		{
			ans1 = nod;
			ans2 = nw;
			return 1;
		}
		if(nw != t)
		{
			if(dfs1(nw, nod) == 1)
				return 1;
		}
	}
	return 0;
}

int main()
{

	cin >> n;

	for(int i=1;i<n;i++)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for(int i=1;i<=n;i++)	
		cin >> c[i];


	for(int i=1;i<=n;i++)
		if(v[i].size() == 1)
		{
			if(dfs1(i, -1) == 0)
			{
				cout << "YES\n1\n";
				return 0;
			}
			break;
		}


	if(dfs2(ans1))
	{
		cout << "YES\n";
		cout << ans1 << '\n';
		return 0;
	}
	if(dfs2(ans2))
	{
		cout << "YES\n";
		cout << ans2 << '\n';
		return 0;
	}
	cout << "NO";
	return 0;
}