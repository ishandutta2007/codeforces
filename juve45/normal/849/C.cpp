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
	cin >> n;
	char c = 'a';
	k = n;
	while(k)
	{
		int s = sqrt(2*k);
		if(s*(s+1)/2 > k) s--;
		for(int i = 1; i <= s+1; i++) cout << c;
		c++;//cout << s+1 << ' ' << c++ << '\n';
		k = k - s*(s+1)/2;
	}	
	cout << 'z';

}