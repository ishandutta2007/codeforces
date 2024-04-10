#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100100
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, off = (1 << 19);
string s;
std::vector<long long> v[DMAX];
long long nr[3], use[DMAX], x, y;

void dfs(long long k, long long c)
{
	nr[c]++;
	use[k]++;
	for (long long i = 0; i < v[k].size(); ++i)
	{
		if(!use[v[k][i]])
			dfs(v[k][i], 1-c);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for (long long i = 1; i < n; ++i)
	{
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1, 0);
	cout << nr[1] * nr[0] - n + 1 << '\n';

}