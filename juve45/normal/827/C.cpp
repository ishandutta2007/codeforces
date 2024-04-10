#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 100001
#define NMAX 1
#define MMAX 1
#define l2(x) (((x^(x-1))+1)>>1)
using namespace std;

int n, aib[4][10][11][DMAX], q, l, r;
string s, e;
int m[266];


int que(int* aib, int pos)
{
	int ans = 0;
	for(int i = pos; i > 0; i-= l2(i))
		ans += aib[i];
	return ans;
}

void upd(int * aib, int pos, int val)
{
	for(int i = pos; i <= DMAX; i+=l2(i))
		aib[i] += val;
}

int main()
{
	m['A'] = 0;
	m['T'] = 1;
	m['G'] = 2;
	m['C'] = 3;
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(int i = 0; i < s.size(); i++)
	{
		int ii = i+1;
		for(int j = 1; j <= 10; j++)
			upd(aib[ m[s[i]] ][ii%j][j], ii, 1);
	}
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> q;
		if(q == 2)
		{
			cin >> l >> r >> e;
			int x = 0;
			for(int j = 0; j < min(int(e.size()), r-l+1); j++)
			{
				int md = e.size();
				int xr = l+j;
				xr %= md;
				int jj = j+1; // pozitia din sirul e. 
				x += que(aib[ m[e[j]] ][xr][e.size()], r) - que(aib[ m[e[j]] ][xr][e.size()], l-1);
			}
			cout << x << '\n';
		}
		else 
		{
			int pos;
			cin >> pos >> e;
			int ii = pos;
			for(int j = 1; j <= 10; j++)
				upd(aib[ m[s[ii-1]] ][ii%j][j], ii, -1);

			s[ii-1] = e[0];

			for(int j = 1; j <= 10; j++)
				upd(aib[ m[e[0]] ][ii%j][j], ii, 1);
		}
	}



}