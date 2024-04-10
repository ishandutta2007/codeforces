#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1100
#define NMAX 1
#define MMAX 1

using namespace std;

int n, v[DMAX], a[DMAX], b[DMAX], f[DMAX], p1, p2, xa, xb;
string s;

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}

	for(int i = 1; i <= n; i++)
	{


		if(a[i] == b[i])
		{
			v[i] = a[i];
			f[a[i]]++;
		}
		else if(p1 == 0)
			p1 = i;
		else p2 = i;
	}


	for(int i = 1; i <= n; i++)
	{
		if(f[i] == 0)
		{
			if(v[p1] == 0) v[p1] = i;
			else v[p2] = i;
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if(a[i] != v[i]) xa++;
		if(b[i] != v[i]) xb++;
	}

	if(xa != 1 || xb != 1)
	{
		swap(v[p1], v[p2]);
	}

	for(int i = 1; i <= n; i++ )
		cout << v[i] << ' ';

}