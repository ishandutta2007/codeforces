#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	int n1 = n-1;
	int ans = (n1%k == 1 ? -1 : 0 ) + 2*((n1+k-1)/k);
	cout << ans << '\n';

	for(int i = 2; i <= k+1; i++)
		cout << 1 << ' ' << i << '\n';
	for(int i = k+2; i <= n; i++)
		cout << i << ' ' << i-k << '\n';
}