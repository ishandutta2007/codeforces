#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, a[DMAX], use[DMAX], m;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	int mn = 1000000000;
	int mx = -1000000000;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i], mn = min(a[i], mn), mx = max(a[i], mx);
	if(k == 1)
		cout << mn << '\n';
	if(k >= 3)
		cout << mx << '\n';
	if(k == 2)
	{
		cout << max(a[1], a[n]) << '\n';
	}
}