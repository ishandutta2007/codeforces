#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 101
#define MMAX 1

using namespace std;

int n, m[12][122][122], c, x, y, s, t, xa, ya, xb, yb, q;

int get(int t, int xa, int xb, int ya, int yb)
{
	return m[t][xb][yb] + m[t][xa][ya] - m[t][xa][yb] - m[t][xb][ya];
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> q >> c;

	for(int i = 1; i <= n; i++ )
	{
		cin >> x >> y >> s;
		m[s][x][y]++;
	}

	for(int x = 0; x <= c; x++)
		for(int i = 1; i <= NMAX; i++)
			for(int j = 1; j <= NMAX; j++)
				m[x][i][j] += m[x][i][j-1] + m[x][i-1][j] - m[x][i-1][j-1];

	for(int i = 1; i <= q; i++)
	{
		cin >> t >> xa >> ya >> xb >> yb;

		int ans = 0;

		for(int j = 0; j <= c; j++)
		{
			ans += get(j, xa-1, xb, ya-1, yb) * ((j+t)%(c+1));
		}
		cout << ans << '\n';

	}

}