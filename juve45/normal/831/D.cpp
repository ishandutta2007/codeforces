#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, ans = 1000000000000000000LL, k, p, a[DMAX], b[2*DMAX];
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k >> p;

	for(long long i = 0; i < n ;i++)
		cin >> a[i];
	sort(a, a + n);

	for(long long i = 0; i < k; i++)
		cin >> b[i];
	sort(b, b + k);

	for(long long i = 0; i <= k-n; i++)
	{
		long long x = 0;

		for(long long j = 0; j < n; j++)
			x = max(abs(a[j] - b[i+j]) + abs(b[i+j] - p), x);

		ans = min(x, ans);
	}

	cout << ans << '\n';

}