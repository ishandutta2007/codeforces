#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	int l1 = n/2;
	int l2 = n/2;

	if(n % 2 == 0)
		l1--;
	l2++;
	while(true)
	{
		if(__gcd(l1, l2) == 1)
		{
			cout << l1 << ' ' << l2;
			return 0;
		}
		l1--;
		l2++;
	}
	
}