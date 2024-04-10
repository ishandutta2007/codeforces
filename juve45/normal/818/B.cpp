#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1000
#define NMAX 1
#define MMAX 1

using namespace std;

int n, m, x[DMAX], v[DMAX], f[DMAX];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)	
	{
		cin >> x[i];
	}

	for(int i = 1; i < m; i++)
	{
		int diff = x[i+1] - x[i];
		if(diff <= 0) diff += n;

		if(v[x[i]] != 0 && v[x[i]] != diff)
		{
			cout << -1 << '\n';
			return 0;
		}

		if(v[x[i]] != diff && f[diff] > 0)
		{
			cout << -1 << '\n';
			return 0;
		}

		if(v[x[i]] == 0)
			f[diff]++;
		v[x[i]] = diff;
	}
	int j = 1;
	for(int i = 1; i <= n; i++)
	{
		if(v[i])
			cout << v[i] << ' ';
		else 
		{
			while(f[j] != 0) j++;
			f[j]++;
			cout << j << ' ';
		}

	}

	cout << '\n';
	return 0;

}