#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1

using namespace std;

int n, in, b, ans, maxx, a[100000], m[19000];

int main()
{
	cin >> n;
	cin >> b;

	for(int i=1; i<=n; i++)
		cin >> a[i];

	for(int i=n;i>0;i--)
		m[i] = max(a[i], m[i+1]);


	for(int i=1; i<=n; i++)
	{

		int c = b / a[i];
		ans = b % a[i] + c*m[i];
		if(ans > maxx)
			maxx = ans;
	}

	cout << maxx;
}