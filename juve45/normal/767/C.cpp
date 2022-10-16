#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1000010
#define MOD 1000000007
using namespace std;

int c[DMAX], nr, sum, n, ans[4], x, y, r, ok;
vector <int> v[DMAX];

int dfs(int k)
{
	int s = 0;
	for(int i=0;i<v[k].size();i++)
		s+=dfs(v[k][i]);

	s+=c[k];
	if(s == sum && k!=r)
	{
		ans[++nr] = k;
		if(nr == 2) ok =1;
		return 0;
	}
	return s;
}

int main()
{

	scanf("%d", &n);

	for(int i=1;i<=n;i++)
	{
		scanf("%d %d", &x, &y);
		sum += y;
		c[i] = y;
		if(x == 0) r = i;
		else v[x].push_back(i);
	}

	if(sum%3)
	{
		printf("-1");
		return 0;
	}
	sum /= 3;

	dfs(r);

	if(ok)
		printf("%d %d", ans[1], ans[2]);
	else
		printf("-1");
 	return 0;
}