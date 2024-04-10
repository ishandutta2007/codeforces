#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, g[DMAX], use[DMAX], m;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << n + n / 2 << '\n';
	for(int i = 2;i <= n; i+=2)
			cout << i << ' ';
	for(int i = 1;i <= n; i+=2)
			cout << i << ' ';
	for(int i = 2;i <= n; i+=2)
			cout << i << ' ';
}