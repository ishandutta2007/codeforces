#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 5010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, v[DMAX][DMAX], p[DMAX], b[DMAX], f[DMAX], ans, last;
string s;

bool check(int k)
{
	memset(f, 0, sizeof f);
	b[0] = k;
	for(int i = 0; i < n; i++)
	{
		p[i] = v[i][0] ^ b[0];
		f[p[i]]++;
	}

	for(int i = 0; i < n; i++)
		b[p[i]] = i;

	for(int i = 0; i < n; i++)
	{
		if(v[0][i] != (p[0] ^ b[i]))
			return false;
		if(v[i][0] != (p[i] ^ b[0]))
			return false;
	}

	for(int i = 0; i < n; i++)
		if(f[i] != 1)
			return false;
	//dbg(k);
	return true;
}

void prt(int k)
{
	b[0] = k;
	for(int i = 0; i < n; i++)
	{
		p[i] = v[i][0] ^ b[0];
		f[p[i]]++;
	}

	for(int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	cout << "? 0 0" << endl;
	cin >> v[0][0];
	for(int i = 1; i < n; i++)
	{
		cout << "? 0 " << i << endl;
		cin >> v[0][i];
		cout << "? " << i << " 0" << endl;
		cin >> v[i][0];
	}
/*
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			v[i][j] = v[i][0] ^ v[0][j] ^ v[0][0];
*/
	for(int i = 0; i < n; i++)
	{
		if(check(i))
			ans++, last = i;
	}
	cout << "!\n" << ans << '\n';
	prt(last);
}