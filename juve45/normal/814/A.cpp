#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, a[144], b[124];
string s;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= k; i++)
	{
		cin >> b[i];
	}
	sort(b+1, b+k+1);
	int j = 1;
	for(int i = k; i > 0; i--)
	{
		while(a[j] != 0) j++;
		a[j] = b[i];
	}

	for(int i = 1; i < n; i++)
	{
		if(a[i] > a[i+1])
		{
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
	return 0;


}