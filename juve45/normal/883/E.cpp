#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, k, g[DMAX], use[DMAX], m, nr, u[DMAX];
string s, st[DMAX];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> n;
	cin >> s;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> st[i];

	for(int i = 0; i < s.size(); i++)
		use[s[i]] = 1;

	nr = n;
	for(int i = 1; i <= n; i++)
	{
		int  ok = 1;
		for(int j = 0; j < st[i].size(); j++)
		{
			if(s[j] != '*' && st[i][j] != s[j])
				ok = 0;
			if(s[j] == '*' && use[st[i][j]])
				ok = 0;
		}

		if(ok == 0)
		{
			nr--;
			continue;
		}

		memset(u, 0, 300 * 4);
		//dbg_v(u, 255);
		for(int j = 0; j < st[i].size(); j++)
		{
			if(s[j] == '*' && u[st[i][j]] == 0)
				g[st[i][j]]++, u[st[i][j]] = 1;
		}
		//dbg_v(g, 255);
	}
	int ans = 0;
	for(int i = 'a'; i <= 'z'; i++)
		if(g[i] == nr)
			ans++;

	cout << ans << '\n';
}