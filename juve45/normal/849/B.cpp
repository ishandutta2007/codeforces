#include <bits/stdc++.h>

#define dbg(x) //cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) //do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok //cerr<<"OK!\n"
#define DMAX 1010
#define NMAX 1
#define MMAX 1

using namespace std;

int n, use[DMAX], v[DMAX];
string s;


int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n;
	for(int i = 1; i <= n; i++) 
	{
		cin >> v[i];
	}

	for(int s = 2; s <= n; s++)
	{
		memset(use, 0, sizeof use);
		use[1] = 1;
		use[s] = 1;
		int x = 1, f = 0, f2 = 0;
		for(int i = 2; i <= n; i++)
		{
			if((s-1)*(v[i]-v[1]) == (v[s]-v[1])*(i-1))
				use[i] = 1,	x++;
			else if(f == 0) f = i, use[f] = 2;
		}
		dbg(s);
		dbg(x);
		dbg(f);
		dbg_v(use, 10);


		if(x == n)
		{
			cout << "NO";
			return 0;
		}
		if(x == n-1)
		{
			cout << "YES";
			return 0;
		}

		x++;
		for(int i = f + 1; i <= n; i++)
		{
			if((s-1)*(v[i]-v[f]) == (v[s]-v[1])*(i-f))
				use[i] = 2,	x++;
		}


		dbg(x);
		dbg_v(use, 10);

		if(x == n)
		{
			cout << "YES";
			return 0;
		}
	}

	int x = 3;
	for(int i = 4; i <= n; i++)
		if((3-2)*(v[i]-v[2]) == (v[3]-v[2])*(i-2)) x++;

	if(x == n)
		cout << "yes";
	else cout << "No";

}