#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, off = (1 << 18), x;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> x;
	if(n == 2 && x == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	if(n == 1) 
	{
		cout << x;
		return 0;
	}
	int a = 0;
	for(int i = 1; i <= n - 2; i++)
	{	
		a ^= i;
		if(i == n-2 && a == x)
		{
			a ^= i;
			cout << ((2 * off) ^ i) << ' ';
			a ^= ((2 * off) ^ i);

		}
		else 
		cout << i << ' ';

	}
	if(x == 0)
	{
		a ^= (n - 1);
		cout << (off ^ (n - 1)) << ' ';
		cout << (off ^ a);
		return 0;
	}
	cout << (off ^ a) << ' ';
	cout << (off ^ x) << ' ';
}