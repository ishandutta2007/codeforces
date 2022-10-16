#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 5010
#define NMAX 1
#define MMAX 1

using namespace std;

string s;
int n, f[DMAX][DMAX], ans[DMAX];
bool pal[DMAX][DMAX];

int fi(int l, int r)
{
	if(f[l][r] != -1)
		return f[l][r];

	if(!pal[l][r])
	{
		f[l][r] = 0;
		return 0;
	}

	int lg=  r - l + 1;
	int m = l + r;
	m /= 2;

	if(lg % 2 == 1)
		f[l][r] = fi(l, m-1) + 1;
	else
		f[l][r] = fi(l, m) + 1;
	return f[l][r];

}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> s;
	memset(f, -1, sizeof f);
	n = s.size();

	for(int i = 0; i < n; i++)
	{
		pal[i][i] = 1;
		if(i + 1 < n && s[i] == s[i+1])
			pal[i][i + 1] = 1;
	}

	for(int j = 2; j <= n; j++)
	{
		for(int i = 0; i + j < n; i++)
		{
			if(s[i] == s[i + j] && pal[i + 1][i + j - 1])
				pal[i][j + i] = 1;
		}
	}
	
	//dbg_v(pal[2], 10);

	for(int i = 0; i < n; i++)
		for(int j = i; j < n; j++)
		{
			ans[fi(i, j)]++;
		}

	for(int i = n-1; i > 0; i--)
		ans[i] += ans[i+1];

	for(int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}