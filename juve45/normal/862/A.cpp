#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, off = (1 << 19), k, op, x;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> x;
	int op = x;
	for(int i = 1; i <= n; i++)
	{	
		cin >> k;
		if(k == x) op++;
		if(k < x) op--;
	}
	cout << op << '\n';
}