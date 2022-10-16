#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;
#define DMAX 10008
using namespace std;

int n, k, x, ans;
string s;
vector <int> v[DMAX];
int use[DMAX];

void dfs(int k)
{
	use[k]=1;
	for(int i=0;i<v[k].size();i++)
	{
		if(!use[v[k][i]])
			dfs(v[k][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> x;
		v[i].push_back(x);
		v[x].push_back(i);
	}

	for(int i=1;i<=n;i++)
	{
		if(!use[i])
			dfs(i), ans++;
	}

	cout << ans << '\n';

	return 0;
}