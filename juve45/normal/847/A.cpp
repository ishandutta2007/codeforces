#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"
#define DMAX 111
#define NMAX 1
#define MMAX 1

using namespace std;

int n, x, l[DMAX], r[DMAX];
vector <int> ll, rr;
string s;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> l[i] >> r[i]; 
		if(l[i] == 0)
			ll.push_back(i); 
		if(r[i] == 0)
			rr.push_back(i);

	}

	int x;
	for(int i = 0; i + 1 < ll.size(); i++)
	{
		x = ll[i];
		while(r[x] != 0) x = r[x];
		r[x] = ll[i+1];
		l[ll[i+1]] = x;
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << l[i] << ' ' << r[i] << '\n';
	}
}