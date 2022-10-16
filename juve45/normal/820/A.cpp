#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 1
#define NMAX 1
#define MMAX 1

using namespace std;

int n, v1, v0, c, a, l, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> c >> v0 >> v1 >> a >> l;
	int pg = 0;
	int v = v0;
	while(pg < c)
	{
		if(pg > 0)
			pg -= l;
		pg += v;
		v = min(v1, v+a);
		ans++;
		//dbg(pg);
	}
	cout << ans << '\n';

}