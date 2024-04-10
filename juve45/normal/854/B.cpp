#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

long long n, k;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	if(k == 0 || n == k) 
	{
		cout << "0 0\n";
		return 0;
	}
	cout << "1 ";
	if(3*k > n)
		cout << n - k;
	else cout << 2 * k;

}