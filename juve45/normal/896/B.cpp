#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1010

using namespace std;

int n, k, x, m, c, p, l, r, v[DMAX], minr = n + 1, maxl = 0;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> c;
	minr = n + 1;
	//int l = 1, r = n;
	for(int i = 1; i <= m; i++)
	{
		//dbg(minr);
		//dbg(maxl);
		cin >> p;
		if( p > c / 2)
		{
			r = n;
			while(v[r] >= p) r--;
			v[r] = p;
			cout << r << endl;
			minr = min(r, minr);
		}
		else{ 
			l = 1;
			while(v[l] <= p && v[l] != 0) l++;
			v[l] = p;
			cout << l << endl;
			maxl = max(l, maxl);
		}
		if(minr - 1 <= maxl || minr == 1 || maxl == n)
		{
			return 0;
		}
	}

		

}