#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, k, x, m, l, r;
string s;
char c1, c2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	cin >> s;
	for(int i = 1; i <= m; i++)
	{
		cin >> l >> r >> c1 >> c2;
		for(int i = l - 1; i < r; i++)
		{
			if(s[i] == c1)
				s[i] = c2;
		}
	}
	cout << s;
		

}