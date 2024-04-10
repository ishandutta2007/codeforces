#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 4000
#define ASD 1000000000
using namespace std;

int n, ans = ASD, use[DMAX], k, f[DMAX], x;
vector <int> v[DMAX];

void dfs(int nod)
{
	queue<int> q;
	q.push(nod);
	use[nod] = 1;
	while(!q.empty())
	{
		nod = q.front();
		q.pop();
		for(int i = 0; i < v[nod].size(); i++)
		{
			if(v[nod][i] == 1000)
				ans = min(use[nod], ans);
			if(!use[v[nod][i]])
			{
				use[v[nod][i]] = use[nod] + 1;
				q.push(v[nod][i]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> x;
		f[x] = 1;
	}

	for(int i=0;i<=2000;i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			if(f[j] == 0) continue;
			int next = i + j - n;
			if(next <= 2000 && next >= 0)
				v[i].push_back(next);
		}
	}

	dfs(1000);
	if(ans == ASD) 
		ans = -1;
	cout << ans << '\n';
}