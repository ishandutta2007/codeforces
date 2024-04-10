#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 10000210
#define MOD 1000000007
using namespace std;
long long n, m, x, mx, lg, k, f1[DMAX], f2[DMAX], ans;
pair<long long, long long> v[DMAX/10], g[DMAX/10];
int main()
{

	scanf("%lld", &n);
	scanf("%lld", &m);
	scanf("%lld", &k);

	for(long long i=1;i<=n;i++)
	{
		scanf("%lld", &x);
		v[i]={x, i};
		f1[v[i].first]++;
	}
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld", &x);
		g[i]={x, i};
		f2[g[i].first]++;
	}

	sort(v+1, v+n+1);
	sort(g+1, g+m+1);
/*
	for(long long i=1;k*i<=n;i++)
	{
		if(v[k*i].first < i-1)
		{
			cout << -1;
			return 0;
		}
	}
*/
	for(long long i=1;i<DMAX;i++)
	{
		f1[i]+=f1[i-1];
		f2[i]+=f2[i-1];
	}

	for(long long i=0;i<DMAX;i++)
	{
		if(f1[i] > (i+1)*k)
		{
			cout << -1;
			return 0;
		}
		ans = max(f1[i] + f2[i] - k*(i+1), ans);
	}
	ans = m-ans;
	cout << ans << '\n';
/*
	for(long long i=1;i<=m;i++)
		cout << g[i].first <<" " << g[i].second << '\n';
*/
	for(long long i=1;i<=ans;i++)
	{
		cout << g[m-i+1].second << ' ';
		/*dbg(g[m-i+1].first);
		dbg(g[m-i+1].second);
		*/
	}
}