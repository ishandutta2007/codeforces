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

int solve(int n)
{
	if(n % 4 == 0)
		return n / 4;
	if(n % 4 == 1)
	{
		if(n >= 9)
			return (n - 9) / 4 + 1;
		return -1;
	}
	if(n % 4 == 2)
	{
		if(n >= 6)
			return (n - 6) / 4 + 1;
		return -1;
	}
	if(n >= 15)
		return (n - 15) / 4 + 2;
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	while(n){
		int x;
		cin >> x;
		cout << solve(x) << '\n';
		n--;
	}
}