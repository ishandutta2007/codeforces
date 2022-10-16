#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1
#define x first
#define y second

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, x, k, mat[DMAX][DMAX], m, xs, xf, ys, yf;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> s;
		for(int j = 0; j < m; j++)
			if(s[j] == '#')
				mat[i][j + 1] = -1;
	}

	cin >> xs >> ys >> xf >> yf;
	mat[xs][ys] = 1;
	for(int i = 0; i <= n; i++)
		mat[i][0] = mat[i][m + 1] = -1;
	for(int i = 0; i <= m; i++)
		mat[0][i] = mat[n + 1][i] = -1;


	queue <pair<int, int> > q;
	q.push({xs, ys});
	while(!q.empty())
	{
		auto pct = q.front();
		q.pop();

		if(pct.x == xf && pct.y == yf)
		{
			cout << mat[xf][yf] - 1;
			return 0;
		}
		
		for(int i = 0; i < 4; i++)
		{
			for(int off = 1; off <= k; off++)
			{
				if(mat[pct.x + off * dx[i]][pct.y + off * dy[i]] == 0)
				{
					mat[pct.x + off * dx[i]][pct.y + off * dy[i]] = mat[pct.x][pct.y] + 1;
					q.push({pct.x + off * dx[i], pct.y + off * dy[i]});
				}
				else if(mat[pct.x + off * dx[i]][pct.y + off * dy[i]] != mat[pct.x][pct.y] + 1)
					break;
			}
			
		}
	}



	cout << -1;
	return 0;

}