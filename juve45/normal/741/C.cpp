
#include <bits/stdc++.h>
#define DMAX 100008
using namespace std;

int x, ans, n, y, use[2*DMAX], a[DMAX], b[DMAX];
vector <int> v[2*DMAX];

void dfs(int k, int c)
{
	use[k] = c;
	for(int i=0;i<v[k].size();i++)
		if(!use[v[k][i]])
			dfs(v[k][i], 3-c);
}


int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
		v[x].push_back(y);
		v[y].push_back(x);
		v[2*i].push_back(2*i+1);
		v[2*i+1].push_back(2*i);
	}	

	for(int i=1;i<=2*n;i++)
		if(!use[i])
			dfs(i, 1);
	for(int i=1;i<=n;i++)
		cout << use[a[i]] << ' ' << use[b[i]] << '\n';
}