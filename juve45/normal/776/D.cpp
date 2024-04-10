#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 200010
using namespace std;

int n, m, d[DMAX], use[DMAX], nrc, x, k;
vector <int> v[DMAX], l[DMAX];

int Not(int x)
{
	if(x > m)
		return x-m;
	return x+m;
}

void dfs(int k)
{
	use[k] = nrc;
	//dbg(k);
	//dbg_v(v[k], v[k].size());
	for(int i=0;i<v[k].size();i++)
		if(!use[v[k][i]])
			dfs(v[k][i]);
}


int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> d[i];

	for(int i=1;i<=m;i++)
	{
		cin >> x;
		for(int j=1;j<=x;j++)
		{
			cin >> k;
			l[k].push_back(i);
		}
	}

	for(int i=1;i<=n;i++)
	{
		//dbg_v(l[i], l[i].size());
		int a = l[i][0];
		int b = l[i][1];
		if(d[i] == 0)
		{
			v[a].push_back(Not(b));
			v[b].push_back(Not(a));
			v[Not(a)].push_back(b);
			v[Not(b)].push_back(a);
		}
		else{
			v[a].push_back(b);
			v[b].push_back(a);
			v[Not(a)].push_back(Not(b));
			v[Not(b)].push_back(Not(a));
		}
	}

	for(int i=1;i<=2*m;i++)
		if(!use[i])
			nrc++, dfs(i);

	//dbg_v(use, 2*m+1);
	for(int i=1;i<=2*m;i++)
	{
		if(use[i] == use[Not(i)])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}