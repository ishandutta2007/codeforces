#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100010

using namespace std;

long long n, k;
vector <long long> v;
long long x[DMAX], s[DMAX];

long long solve(long long p)
{
	memset(s, 0, sizeof(s));
	long long sgn = 1, ans = 0;
	map <long long, long long> m;

	//if(p < 0) sgn = -1, p=-p;
	m[0]=1;
	for(long long i=1;i<=n;i++)
	{
		s[i] = x[i] + s[i-1];
		ans += m[s[i]-p];
		m[s[i]]++;
	}
	return ans;

}


int main()
{
	cin >> n >> k;
	long long kmax = 1, ans = 0;
	while(kmax <= 1000000000000000LL)
	{
		v.push_back(kmax);
		kmax*=k;
		if(kmax == 1) break;
    }
	for(long long i=1;i<=n;i++)
		cin >> x[i];

	for(long long i=0;i<v.size();i++)
	{
		//dbg(solve(v[i]));
		ans += solve(v[i]);
	}
	cout << ans << '\n';
}