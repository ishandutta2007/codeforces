#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100009

using namespace std;

long long n, minn = 0;
long long maxx = 0, ans = -20000000090000000;
long long d[DMAX], v[DMAX];
int main()
{

	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> v[i];
		d[i - 1] = abs(v[i] - v[i - 1]);
	}


	d[0] = 0;
	long long sgn = 1;
	for(long long i = 1; i < n; i++)
		d[i] = d[i - 1] + d[i] * sgn, sgn *= -1;


	for(long long i = 1; i < n; i++)
	{
		ans = max (ans, d[i] - minn);
		ans = max (ans, maxx - d[i]);
		if(i%2 == 1) maxx = max(maxx, d[i]);
		else minn = min(minn, d[i]);
	}

	cout << ans << '\n';

}