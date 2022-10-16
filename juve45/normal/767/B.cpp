#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100010
#define MOD 1000000007
using namespace std;

long long n, x, s, t, f, fr, ans = 100000000000000LL, in;
priority_queue <long long> p;

int main()
{
	cin >> s >> f >> t;
	fr = s;

	cin >> n;
	for(long long i=1;i<=n;i++)
	{
		cin >> x;
		if(ans > fr-x+1 && x-1+t <= f)
		{
			ans = fr-x+1;
			in = x-1;
		}
		if(x > fr && x+t <= f) 
		{
			cout << fr << '\n';
			return 0;
		}
		else fr += t;
		//else free = max(x+t, free + t);
	}
	if(fr <= f-t) 
		{
			cout << fr;
			return 0;
		}
	cout << in;
 	return 0;
}